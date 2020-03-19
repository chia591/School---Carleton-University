function todo(){
    console.log("Running");

    let counter = 0;

    let radioList = document.getElementById("radioList");
    document.getElementById("btnAdd").addEventListener("click", btnAdd);
    document.getElementById("btnRemove").addEventListener("click", btnRemove);
}

function btnAdd(){
    let input = new String(document.getElementById("txtItem").value);
    if ( input != ""){
        console.log(input);

        let radio = makeRadioButton("toDoItem", counter, input);
        radioList.appendChild(radio);
        radioList.appendChild(document.createElement("br"));

        counter++;
    }else{
        console.log("blank");
    }
}

function btnRemove(){

}

function makeRadioButton(name, value, text) {

    var label = document.createElement("label");
    var radio = document.createElement("input");
    radio.type = "radio";
    radio.name = name;
    radio.value = value;

    label.appendChild(radio);
    label.appendChild(document.createTextNode(text));
    return label;
}