const app = require('express')();
const http = require('http').createServer(app);

function todo(){
    console.log("Running");

    let chkboxList = document.getElementById("chkboxList");
    document.getElementById("btnAdd").addEventListener("click", btnAdd);
    document.getElementById("btnRemove").addEventListener("click", btnRemove);
    document.getElementById("btnTogHglt").addEventListener("click", btnHighlight);
    document.getElementById("btnSort").addEventListener("click", btnSort);
}

function btnAdd(){
    let input = new String(document.getElementById("txtItem").value);
    if ( input != ""){
        console.log(input);

        let chkbox = makeCheckBox("chkList", input);
        chkbox.className = "chkList";
        chkboxList.appendChild(chkbox);

    }else{
        console.log("blank");
    }
}

function btnRemove(){
    let children = document.getElementsByClassName("chkList");
    for(let x = children.length - 1; x > -1; x--){
        let child = children[x];
        if(child.childNodes[0].checked == true){
            console.log(children);
            child.remove();
        }
    }
}

function makeCheckBox(name, text) {

    var label = document.createElement("label");

    var chkbox = document.createElement("input");
    chkbox.type = "checkbox";
    chkbox.id = "box";
    chkbox.name = text;
    chkbox.checked = false;

    label.appendChild(chkbox);
    label.appendChild(document.createTextNode(text));
    label.appendChild(document.createElement("br"));
    return label;
}

function btnHighlight(){
    console.log(document.getElementById("chkboxList"));
    console.log(document.getElementsByClassName("chkList"));
    let children = document.getElementsByClassName("chkList");
    for(let x = children.length - 1; x > -1; x--){
        let child = children[x];
        if(child.childNodes[0].checked == true){
            if(child.style.color == "red"){
                child.style.color = "rgb(0, 0, 0)";
                child.style.backgroundColor = "rgb(255, 255, 255)";
            }else{
                child.style.color = "red";
                child.style.backgroundColor = "rgb(255, 191, 202)";
            }
        }
    }
}

function btnSort(){
    let children = document.getElementsByClassName("chkList");
    let swch = true;
    let shouldSwch;

    while (swch){
        let x;
        console.log(children);
        console.log("rotate");
        swch = false;
        for(x = 0; x < children.length - 1; x++){
            console.log("cycle");
            shouldSwch = false;
            if(children[x].childNodes[1].data > children[x + 1].childNodes[1].data){
                console.log("cycle find");
                shouldSwch = true;
                break;
            }
        }

        if (shouldSwch == true){
            console.log("replace");
            let before = children[x];
            let child = children[x + 1];
            chkboxList.removeChild(child);
            chkboxList.insertBefore(child, before);
            swch = true;
        }
        console.log("end rotate");
    }
    console.log("done");
    let sorted = children;
}