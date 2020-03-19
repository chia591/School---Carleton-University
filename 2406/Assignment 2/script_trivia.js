let user = [];
let storedQuestion = null;
let selectedAnwser = null;
let socket;



// for ease of understanding please read the included  Read Me.txt



function ONLOAD_trivia(){ //most socket.io stuff is found here
    let id = window.location.href.split("=")[1]; //gets the name of the user from the url
    if (id == undefined){
        id = "guest"
    };
    socket = io(); 
    socket.on('connect', function(data){ //initialising 
        //console.log('socket.io - username (sent)');
        socket.emit('username', { customId: id });
        //console.log('socket.io - user_send (sent)');
        socket.emit('user_send', socket.id);
    });
    socket.on('user_return', function(data){ // when receiving the user's profile, its displayed using this function
        //console.log('socket.io - user_return (received)');
        user = data;
        //console.log(user);
        let box = document.createElement("div");
        let name = document.createElement("label");
        //console.log(user.currentScore);
        name.innerText = "player: " + user.customId + "  [" + user.currentScore + "]";
        box.appendChild(name);
        let NameTag = document.getElementById("divName");
        for(let i = NameTag.childElementCount; i > 0; i--){
            NameTag.removeChild(NameTag.firstChild);
        }
        NameTag.appendChild(box);
    });
    socket.on('question', function(data){ //asks to render the question everytime using this.
        storedQuestion = data;
        render(data);
    });
    socket.on('roundEnd', function(data){ //Displays the end screen when the round is over
        let winnersNames = "The winners for this round ";
        if(data.length == 1){
            winnersNames += "is: ";
        }else{
            winnersNames += "are: ";
        }
        for(let i = 0; i < data.length; i++){
            if(i == 0){
                winnersNames += data[i].customId;
            }else{
                winnersNames += ", " + data[i].customId;
            }
        }
        
        let questionArea = document.getElementById("gamePage");
        for(let i = questionArea.childElementCount; i > 0; i--){
            questionArea.removeChild(questionArea.firstChild);
        }
        let endScreen = document.createElement("h2");
        endScreen.appendChild(document.createTextNode(winnersNames));
        endScreen.style.border = "1px solid blue";
        questionArea.appendChild(endScreen);
    });
    socket.on('players', function(data){ //Renders the player list
        renderPlayerList(data);
    });
};

function renderPlayerList(x){ //Displays the player list
    console.log("player list updated");
    let list = document.getElementById('playerList')
    for(let i = list.childElementCount; i > 0; i--){
        list.removeChild(list.firstChild);
    }
    for(let i = list.childElementCount; i > 0; i--){
        list.removeChild(list.firstChild);
    }
    for(let i = list.childElementCount; i > 0; i--){
        list.removeChild(list.firstChild);
    }
    for(let i = 0; i < x.length; i++){
        let div = document.createElement("div");
        let text = document.createTextNode(x[i].customId + " [" + x[i].currentScore + "]")
        div.appendChild(text);
        list.appendChild(div);
    }
}

function confirm(){ //function whenever a radio button is pressed so that they can be locked and sends a message to the server
    let childrens = document.getElementsByClassName("questions")[0].children;
    //console.log(childrens);
    for(let i = 1; i < childrens.length; i++){
        let child = childrens[i].children;
        if(child[0].childNodes[0].checked == true){
            child[0].style.backgroundColor = "#A9A9A9";
            child[0].removeChild(child[0].firstChild)
            selectedAnwser = child[0].childNodes[0];
            console.log(selectedAnwser.data);
            console.log(storedQuestion.correct_answer);
            if(selectedAnwser.data == storedQuestion.correct_answer){
                socket.emit('correct', user);
            }else{
                socket.emit('incorrect', user);
            }

        }if(child[0].childNodes[0].checked == false){
            child[0].style.backgroundColor = "";
            child[0].removeChild(child[0].firstChild)
        }
    }
}

//Adds the question to the game page
function render(x){ //Displays the question with it's anwsers
    socket.emit('user_send', socket.id);
    let questionArea = document.getElementById("gamePage");
    console.log("clear");
    for(let i = questionArea.childElementCount; i > 0; i--){
        questionArea.removeChild(questionArea.firstChild);
    }
    for(let i = questionArea.childElementCount; i > 0; i--){
        questionArea.removeChild(questionArea.firstChild);
    }
    for(let i = questionArea.childElementCount; i > 0; i--){
        questionArea.removeChild(questionArea.firstChild);
    }
    let question = document.createElement("div");
    let title = document.createElement("h3");
    title.appendChild(document.createTextNode(x.question));
    title.appendChild(document.createElement("br"));
    question.appendChild(title);

    let anwsers = new Array(x.incorrect_answers.length + 1);
    for(let y = 0; y < anwsers.length - 1; y++){
        anwsers[y] = makeRadioButton("q", "N", x.incorrect_answers[y]);
    }
    anwsers[anwsers.length - 1] = makeRadioButton("q", "Y", x.correct_answer);
    shuffle(anwsers);
    for(let y = 0; y < anwsers.length; y++){
        let group = document.createElement("div");
        group.appendChild(anwsers[y]);
        group.className = y;
        question.appendChild(group);
    }
    question.className = "questions"
    questionArea.appendChild(question);
}

//note Name Groups the buttons, value gives it individuality
function makeRadioButton(name, value, text) { //small function that creates radio buttons
    let label = document.createElement("label");
    let radio = document.createElement("input");
    radio.type = "radio";
    radio.name = name;
    radio.value = value;
    radio.addEventListener("click", confirm);

    label.appendChild(radio);
	label.appendChild(document.createTextNode(text));
	label.appendChild(document.createTextNode(" "))
	label.appendChild(document.createElement("br"));
    return label;
}

function shuffle(array) { //SMall arra shuffler for rendering
	array.sort(() => Math.random() - 0.5);
}