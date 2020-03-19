function ONLOAD_name(){
    document.getElementById("btnConfirm").addEventListener("click", btnConfirm);
}

function btnConfirm(){
    let input = new String(document.getElementById("txtUsername").value);//grabs the input from the user
    if (input != ""){
        /*
        var socket = io();
        socket.on('connect', function(data){
            socket.emit('username', { customId: input });
        });
        */
        console.log(input);
        window.location.href = ('http://localhost:3000/game?id=' + input);
        window.location = ('http://localhost:3000/game?id=' + input); //redirects you to a new page with the id in the url for ease of acess
        return false;
    }else{
        console.log("Blank username");// nothing was in the input box
    }
}