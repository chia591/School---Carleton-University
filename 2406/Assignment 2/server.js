var app = require('express')();
var http = require('http').createServer(app);
var io = require('socket.io')(http);
var url = require('url');
var fs = require('fs');
const colors = require('colors');



// for ease of understanding please read the included  Read Me.txt



colors.setTheme({
    join: 'green',
    leave: 'red',
    server: 'rainbow',
    playerAction: 'blue',
    update: 'yellow'
});

app.get('/', function(req, res){ //gets the default (main page)
    res.sendFile(__dirname + '/trivia_name.html');
});

app.get('/game?', function(req, res){ //This will be the login into a certain account
    let id = req.url.split("=")[1];
    console.log("User: " + id);
    res.sendFile(__dirname + '/trivia_game.html');
});

app.get('/game', function(req, res){ //Default, this can be a guest
    res.sendFile(__dirname + '/trivia_game.html');
});

app.get('/script_title.js', function(req, res){// code for main page
    res.sendFile(__dirname + '/script_title.js');
});

app.get('/script_trivia.js', function(req, res){ //code for the trivia game
    res.sendFile(__dirname + '/script_trivia.js');
});

//USERS
var users = []; //all user accounts ever created
var onlineUsers = []; //Only active users on the server
var responses = 0; // responces, this is used to know i to go to the next question or not during gameplay
/*
customId = Username
userId = currentId givin to the current session when connected
privateId = Id given to the account without showing the username
overallScore = score the account has over the livespam of the account
currentScore = score for the current session
*/

io.on('connect', function(socket){
    socket.on('disconnect', function(){
    });
});

io.on('connection', function(socket){
    socket.on('username', function(data){ //username is in the ONLOAD of the main game server
        console.log('Socket.io - Username'.update);
        let newAccount = true; //toggle if the account connecting is a new account or not
        for(let i = 0; i < users.length; i++){
            if(users[i].customId == data.customId){
                newAccount = false; 
            }
        }
        if(newAccount == true){ //so it is a new account, its creating the profile
            let userInfo = new Object();
            userInfo.customId = data.customId;
            userInfo.userId = socket.id;
            userInfo.privateId = null;
            userInfo.overallScore = 0;
            userInfo.currentScore = 0;
            users.push(userInfo);
            onlineUsers.push(userInfo);
            console.log("New Player: ".playerAction + JSON.stringify(userInfo).join);
            console.log();
        }else{ //Since its not a new account, its going to grab the profile and add it to online players
            let i = 0;
            while(i < users.length){
                if(users[i].customId == data.customId){
                    break;
                }
            }
            let userInfo = users[i];
            userInfo.userId = socket.id;
            userInfo.currentScore = 0;
            onlineUsers.push(userInfo);
            console.log("Returning Player: ".playerAction + JSON.stringify(userInfo).join);
            console.log();
        }
        if(test == null){ getGame(); console.log("asked"); } //starts the game whenever the test variable is empty
        else{ //this should allow any new joiner to play the game
            console.log(currentQuestion);
            io.emit('question', currentQuestion);
        } 
        io.emit('players', onlineUsers); //updates the player list
    });
    socket.on('disconnect', function (data) {
        console.log('Socket.io - disconnect'.update);
        for(let i = 0; i < onlineUsers.length; i++){// updates the online player list
            let c = onlineUsers[i];
            if(c.userId == socket.id){
                console.log(("removed : " + socket.id).leave);
                console.log();
                onlineUsers.splice(i,1);
                break;
            }
        }
        for(let i = 0; i < users.length; i++){// updates the total player list
            if(users[i].userId == socket.id){
                users[i].userId = null;
            }
        }
        if(onlineUsers.length == 0){ //more resetting
            test = null;
            currentQuestion = null;
            clearTimeout(t);
            clearTimeout(t);
            clearTimeout(t);
            clearTimeout(t);
            clearTimeout(t);
            clearTimeout(t);
            clearTimeout(t);
            clearTimeout(t);
        }
        io.emit('players', onlineUsers);
    });
    socket.on('user_send', function(data){
        for(let i = 0; i < onlineUsers.length; i++){
            if(onlineUsers[i].userId == data){
                let output = JSON.stringify(onlineUsers[i]);
                socket.emit('user_return', onlineUsers[i]);
                console.log(data + " asked for: " + output);
            }
        }
        io.emit('players', onlineUsers);
        console.log('Socket.io - user_Send'.update);
    });
    socket.on('correct', function(data){// when the user gets the correct anwser they gain points (better explanation in read me for why its 50)
        //console.log("win");
        let out;
        for(let i = 0; i < onlineUsers.length; i++){
            if(onlineUsers[i].userId == socket.id){
                onlineUsers[i].overallScore += 50;
                onlineUsers[i].currentScore += 50;
                break;
            }
        }
        for(let i = 0; i < users.length; i++){
            if(users[i].userId == socket.id){
                users[i].overallScore += 50;
                users[i].currentScore += 50;
                out = users[i];
                break;
            }
        }
        responses++;
        if(responses == onlineUsers.length){ //This is to skip the question and to go onto the next one
            console.log("next");
            clearTimeout(t);
            clearTimeout(t);
            clearTimeout(t);
            clearTimeout(t);
            clearTimeout(t);
            timeoutHandles();
            responses = 0;
        }
        socket.emit('user_return', out); //updates player's personal score board
        io.emit('players', onlineUsers); //updates player list
    });
    socket.on('incorrect', function(data){ //same really as correct
        //console.log("lost");
        let out;
        for(let i = 0; i < onlineUsers.length; i++){
            if(onlineUsers[i].userId == socket.id){
                onlineUsers[i].overallScore -= 50;
                onlineUsers[i].currentScore -= 50;
                break;
            }
        }
        for(let i = 0; i < users.length; i++){
            if(users[i].userId == socket.id){
                users[i].overallScore -= 50;
                users[i].currentScore -= 50;
                out = users[i];
                break;
            }
        }
        responses++;
        if(responses == onlineUsers.length){
            console.log("next");
            clearTimeout(t);
            clearTimeout(t);
            clearTimeout(t);
            clearTimeout(t);
            clearTimeout(t);
            timeoutHandles();
            responses = 0;
        }
        socket.emit('user_return', out);
        io.emit('players', onlineUsers);
    });
});

let test = null; //this stores the test from opentdb
let currentQuestion = null; //stores the question that the test is currently at so new joiners can join
let step = 0; //for the recursive functions

function getGame(){ //this is just asking for the quiz from the website
    const request = require('request');
    request('https://opentdb.com/api.php?amount=5', function (error, response, body) {
        test = JSON.parse(body);
        if(test["response_code"] == 0){
            test = test["results"]
            console.log("request - test".update);
            startGame();
        }
    });
}

var t;

function startGame(){// starts the game
    console.log('Socket.io - Question sent to clients'.update);
    for(let i = 0; i < onlineUsers.length; i++){
        onlineUsers[i].currentScore = 0;
    }
    //variables
    responses = 0;
    step = 0;

    //Queuing up the questions
    timeoutHandles();
}

function timeoutHandles(){ //starts asking questions
    if(onlineUsers.length != 0){
        //sending questions
        if(step < test.length){
            console.log("question " + step);
            currentQuestion = test[step];
            currentQuestion.question = (step + 1) + ". " + currentQuestion.question;
            io.emit('question', currentQuestion);
            step++;
            responses = 0;
            console.log("timer start");
            t = setTimeout(timeoutHandles, 30000);
        }
        //sending the end screen
        else if(step == test.length){
            console.log("round End")
            let winners = [onlineUsers[0]];
            for(let l = 1; l < onlineUsers.length; l++){
                if(onlineUsers[l].currentScore > winners[0].currentScore){
                    winners = [onlineUsers[l]];
                }else if(onlineUsers[l].currentScore == winners[0].currentScore){
                    winners.push(onlineUsers[l]);
                }else{}
            }
            io.emit('roundEnd', winners);
            io.emit('players', onlineUsers);
            //console.log("Socket.io - Alert sent anouncing winners".update);
            step++;
            console.log("timer start");
            setTimeout(timeoutHandles, 5000);
        }
        //starting up new round
        else{
            console.log('newGame');
            getGame();
        }
    }else{
        console.log("Game has stopped, no online players")
    }
}

http.listen(3000, function(){ //localhost:3000
    console.log('Listening on *:3000'.server);
});