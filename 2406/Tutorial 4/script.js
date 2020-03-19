
console.log("Functioning properly.");
var list = [];


function addElement() {
    var checkbox = document.createElement("input");
    checkbox.type = "checkbox";
    var value = document.getElementById("myinput").value;
    var t = document.createElement("LABEL");


    if (value === '') {
        console.log("Invalid input");
    } else {
        value = {"name":value}
        list.push(value);
        value = value["name"]+"\n"
        t.innerText = value;
        document.getElementById("div1").appendChild(checkbox);
        document.getElementById("div1").appendChild(t);
        console.log(value);
    }
    console.log(list);
    document.getElementById("myinput").value = "";

    var http = new XMLHttpRequest();
    http.open( "POST", 'http://localhost:3000/update', true );
    let output = JSON.stringify(list);
    http.send(output);
    console.log(output);
}

function addElement2(value){
    for(var key in value){
        var checkbox = document.createElement("input");
        checkbox.type = "checkbox";
        var t = document.createElement("LABEL");
        key = key[i]["name"]+"\n"
        t.innerText = key;
        document.getElementById("div1").appendChild(checkbox);
        document.getElementById("div1").appendChild(t);
        console.log(value);
    }    
}

function removeElement(){
    let div = document.getElementById("div1");
    for(let i = 0; i < div.childNodes.length; i++){
		if(div.childNodes[i].type === "checkbox" && div.childNodes[i].checked){
            div.removeChild(div.childNodes[i+1]);
            div.removeChild(div.childNodes[i]);
            list.pop(i);
            i = i-2;
        }
    }
    var http = new XMLHttpRequest();
    http.open( "POST", 'http://localhost:3000/update', true );
    let output = JSON.stringify(list);
    http.send(output);
    console.log(output);
}

function spillElements(){

    list = sendPost();

    for(let i = 0; i< list.length; i++){
        var checkbox = document.createElement("input");
        checkbox.type = "checkbox";
        var t = document.createElement("LABEL");
        key = list[i]["name"]+"\n"
        t.innerText = key;
        document.getElementById("div1").appendChild(checkbox);
        document.getElementById("div1").appendChild(t);
    }
    console.log(list);
}


function sendPost(){

    var xmlHttp = new XMLHttpRequest();

    xmlHttp.open( "POST", 'http://localhost:3000/start', false );
	xmlHttp.send( null );
	let newdata = xmlHttp.responseText;
	var currentTest = JSON.parse(newdata);
    list = currentTest;
    console.log(list);
    return list;  
}