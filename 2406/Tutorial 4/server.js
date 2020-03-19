const express = require('express');
const app = express();
const http = require('http').createServer(app);
const io = require('socket.io')(http);

var list = [{"name":"Dog"}, {"name":"Cat"}, {"name":"HAM"}];

app.use(express.json({type: '*/*'}));

app.get('/', function(req, res) {
    res.sendFile(__dirname + '/Tutorial3.html');
    console.log("/Tutorial3.html Grabed");
});

app.get('/script.js', function(req, res) {
    res.sendFile(__dirname + '/script.js');
    console.log("/script.js Grabed");
});

app.post('/start', function(req, res) {
    let body = JSON.stringify(list);
    console.log("List sending...");
    console.log(body);
    res.send(body);
});

app.post('/update', (req, res) => {
    const input = req.body.name;
    res.type('text/json');
    list = req.body;
    console.log(list);
    res.end();
});

http.listen(3000, function () {
    console.log("Listening on *:3000");
});