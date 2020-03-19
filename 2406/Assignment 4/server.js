//Create express app
const express = require('express');
let app = express();

//Database variables
let mongo = require('mongodb');
let MongoClient = mongo.MongoClient;
let db;

//View engine
app.set("view engine", "pug");

//Code:
app.get("/questions", logRequest, getQuestions);
app.get("/questions/:qID", logRequest, getQuestion);
app.get("/createquiz", logRequest, createQuiz);
app.get("/quizzes", logRequest, gQuizzes);
app.get("/quiz/:quizID", logRequest, quizz);
app.post("/quizzes", logRequest, pQuizzes);

//Default function to display all request incomming to the server
function logRequest(req, res, next){
    console.log("Method: " + req.method);
	console.log("URL: " + req.url);
	console.log(req.query);
	next();
}

function getQuestions(req, res, next){
    //setting variables from request param
    let difficulty = req.query['difficulty'];
    let category = req.query['category'];
    let output = []; //Output
    let params = {}; //serch parameters

    //Confirming the request params to be
    if (difficulty == 'easy' || difficulty == 'medium' || difficulty == 'hard'){}
    else{
        console.log("difficulty variable has been changed back to default value (undefined)")
        difficulty = undefined;
    }

    //setting the output values from the list.
    if(difficulty == undefined && category == undefined){ //If there is no specification
        params = {};
    }else if(difficulty != undefined && category == undefined){ //if difficulty is specified
        params = {difficulty : difficulty};
    }else if(difficulty == undefined && category != undefined){ //If the category is specified
        params = {category : category};
    }else{ //If both is specified
        params = {category : category, difficulty : difficulty}
    }

    db.collection("questions").find(params).limit(25).toArray(function(err, results){ //returns the first 25 results using the serch parameters
        if(err) throw err;
        output = results;

        res.format({ //sends back the info: html/json
            'text/html':function(){
                res.render('pages/questions', {questions: output});
            },
            'application/json': function(){
                res.send({questions: output});
            },
            'default': function(){
                res.render('pages/questions', {questions: output});
            }
        });
    });
};

function getQuestion(req, res, next){ //gets and returns a specific question 
    let id = req.params.qID; //gets the id from the url params
    let output = []; //Output
    let o_id = new mongo.ObjectID(id); //converts it to a mongodb ObjectID object
    db.collection("questions").find({"_id": o_id}).limit(1).toArray(function(err, results){ //looks for one results
        if(err) throw err;
        output = results;
        if(output.length == 0){ //if no results shows up sends 404
            console.log("cant find a question with a specific id: " + id);
            res.status(404).end();
            return;
        }
        output = results[0]; //changes the output

        console.log(output);
        res.format({ //sends the question back either with direct json format or an html using pug
            'text/html':function(){
                res.render('pages/question', {x: output});
            },
            'application/json': function(){
                res.send(results);
            },
            'default': function(){
                res.render('pages/question', {x: output});
            }
        });
    });
};

//not done
function createQuiz(req, res, next){ //a creation page to make a new quizz
    res.render('pages/createQuiz');
};

//not confirmed working
function pQuizzes(req, res, next){ //takes the sent json file and adds it to the data base
    let body = req.body["quiz"]; //extracts the quiz
    if(body.creator == undefined || body.tags == undefined || body.questions.length == 0){ //checks if there are no missing content
        res.send(404).end();
        return;
    }

    for(let x = 0; x < body.questions.length; x++){ //checks if each question exist or not
        let o_id = body.questions[x]._id;
        db.collection("questions").find({"_id": o_id}).limit(1).toArray(function(err, results){
            if(err) throw err;
            if(results.length == 0){
                res.status(404).end();
                return;
            }
        });
    }
    
    body.tag = body.tag.toLowerCase().split(" "); //splits the tags so that it can be serched by mongodb and also puts all string to lower case

    db.collection("quizzes").insertOne(body, function(err, result){ //adds it to the data base.
        if(err) throw err;
    });
    res.status(200).end(); //sends back 200 status
}

//not confirmed working
function gQuizzes(req, res, next){
    //setting variables from request param
    let creator = req.query['creator'];
    let tag = req.query['tag'].toLowerCase(); //sets the string to lowercase
    let output = []; //Output
    let params = {}; //serch parameters

    //setting the output values from the list.
    if(creator == undefined && tag == undefined){ //If there is no specification
        params = {};
    }else if(creator != undefined && tag == undefined){ //if creator is specified
        params = {creator : creator};
    }else if(creator == undefined && tag != undefined){ //If the tag is specified
        params = {tag : [tag]};
    }else{ //If both is specified
        params = {creator : creator, tag : [tag]}
    }

    db.collection("quizzes").find(params).limit(25).toArray(function(err, results){ //finds the top 25 quizz in the data base
        if(err) throw err;
        output = results;

        res.format({ //sends back the info: html/json
            'text/html':function(){
                res.render('pages/quizzes', {quizzes: output});
            },
            'application/json': function(){
                res.send({quizzes: output});
            },
            'default': function(){
                res.render('pages/quizzes', {quizzes: output});
            }
        });
    });
}

//not confirmed working
function quizz(req, res, next){ //finds a single quiz
    let id = req.params.quizID; //sets the id from the url
    let output = []; //Output
    let o_id = new mongo.ObjectID(id); //converts into mongo ObjectID object
    db.collection("questions").find({"_id": o_id}).limit(1).toArray(function(err, results){  //tries to find the specific quiz with the provided id
        if(err) throw err;
        output = results;
        if(output.length == 0){ //cant find results, sends 404
            console.log("cant find a question with a specific id: " + id);
            res.status(404).end();
            return;
        }
        output = results[0];

        console.log(output);
        res.format({ //sends the question back either with direct json format or an html using pug
            'text/html':function(){
                res.render('pages/quiz', {x: output});
            },
            'application/json': function(){
                res.send(results);
            },
            'default': function(){
                res.render('pages/quiz', {x: output});
            }
        });
    });
}

// Initialize database connection
MongoClient.connect("mongodb://localhost:27017/", function(err, client) {
  if(err) throw err;

  //Get the a4 database
  db = client.db('a4');
  
  // Start server once Mongo is initialized
  app.listen(3000);
  console.log("Listening on port 3000");
});