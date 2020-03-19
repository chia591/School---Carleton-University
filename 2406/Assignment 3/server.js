const express = require('express');
const app = express();
const fs = require('fs');
const path = require('path');

const climit = 10;
const ammQuestions = 500;

let idCount = {};
let storedId = [];

app.post("/sessions", function(req, res){ //creates a random id and sends that id to the client so that they dont get repeated questions,
    /*
    let id = Math.floor((Math.random() * 1000000) + 100000);
    id = id.toString();
    console.log("/sessions ---- POST : " + id);
    res.status(201).send(id);
    */
    let toggle = true;
    while(toggle == true){
        let id = Math.floor((Math.random() * 1000000) + 100000);
        id = id.toString();
        if(storedId != []){
            toggle = false;
            for(let i = 0; i < storedId.length; i++){
                if(storedId == id){
                    toggle = true;
                    break;
                }
            }
            if(toggle == false){
                storedId.push(id);
                idCount[id] = [];
                res.status(201).send(id).end();
            }
        }else{
            storedId.push(id);
            idCount[id] = [];
            toggle = false;
            res.status(201).send(id).end();
        }
    }
    //console.log(storedId);
    //console.log(idCount);
});

app.get("/sessions", function(req,res){ //sends a list of all the ids on the system
    res.status(200).send(storedId).end();
});

app.delete("/sessions/:sessionid", function(req, res){ //deletes a specific id
    let id = req.params.sessionid;
    for(let i = 0; i < storedId.length + 1; i++){
        if(id == storedId[i]){
            delete storedId[i];
            storedId = JSON.stringify(storedId, (k, v) => Array.isArray(v) ? v.filter(e => e !== null) : v, 2 );
            storedId = JSON.parse(storedId);
            delete idCount[id];
            console.log("deleted");
            res.status(200).end();
            break;
        }
        if(i == storedId.length){
            console.log("failed to Delete");
            res.status(404).end();
        }
    }
});

app.get("/questions", function(req, res){ //asking for questions
    //console.log(req.query);
    //console.log(req.query['id']);
    console.log("get questions");
    let limit = req.query['limit'];
    if(limit == undefined){ limit = climit; } //setting default limit (in this case 10)
    else{ limit = limit.toString();}
    let difficulty = req.query['difficulty'];
    let category = req.query['category'];
    let token = req.query['id'];
    let status = null; //0 (success), 1 (no results or not enough questions to fulfill request), 2 (invalid token, see ‘Adding Sessions’ section)

    let output = [];
    for(let i = 1; i < limit + 1; i++){ //Starts cycling through the questions
        if(i == 501){ //if it hits question 501 (that does not exit) status 1, break
            status = 1;
            break;
        }

        let fileName = "questions/" + i + ".txt"; //this is opening the files to read the content
        let file = fs.readFileSync(fileName, 'utf-8');
        file = JSON.parse(file);

        if(token != null && i == 1){//checks if the token is valid or not, if the token is not valid then it will exit the loop and status = 2
            let skip = false;
            for(let x = 0; x < storedId.length + 1; x++){
                if(storedId[x] == token){ break; }
                if(x == storedId.length){ skip = true; }
            }
            if(skip == true){
                status = 2;
                break;
            }
        }

        if(token != null){//checks if the question has been published or not yet
            let nextQuestion = false;
            for(let x = 0; x < idCount[token].length; x++){
                if(idCount[token][x] == i){ nextQuestion = true }
            }
            if(nextQuestion == true){
                limit++;
                continue;
            }
        }

        if(difficulty == undefined){} //if it does not pass the criterea it skips to the next question
        else if(difficulty >= 1 && difficulty <= 3){
            if(file['difficulty_id'] != difficulty){
                limit++;
                continue;
            }
        }else{}

        if(category == undefined){}//if it does not pass the criterea it skips to the next question
        else if(category >= 1 && category <= 24){
            if(file['category_id'] != category){
                limit++;
                continue;
            }
        }else{}

        if(token != null){ idCount[token].push(i); } //if it gets this far, it will add the question to its designated id and then add it to the output JSON
        output.push(file);
    }
    console.log("limit: " + limit);
    console.log("difficulty: " + difficulty);
    console.log("category: " + category);
    console.log("token: " + token);
    console.log("status: " + status);
    console.log();
    if(status == 2 || status == 1){ //sends the error
        res.send({"status": status});
    }else if(status == null){ //sends a status 0 (pass) and the results
        res.send({"status": 0, "results": output});
    }else{
        res.sendStatus(404); //should never get here 
    }
});


























app.listen(3000);
console.log("Server listening at http://localhost:3000");