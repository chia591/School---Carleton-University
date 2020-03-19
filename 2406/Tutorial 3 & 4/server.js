/*
const app = require('express');
const http = require('http').createServer(app);
const io = require('socket.io')(http);

//Helper function for sending 404 message
function send404(response) {
	response.writeHead(404, { 'Content-Type': 'text/plain' });
	response.write('Error 404: Resource not found.');
	response.end();
}

let server = http.createServer(function (req, res) {
	if (req.method == 'GET') {
		
		//Add routes here to handle GET requests
		//For example:
		if (req.url == '/'){
			//Handle response here for the resource "/"
			fs.readFile('todo.html', function(err, data){
				res.writeHead(200, {'Content-Type': 'text/html'});
				res.write(data);
				res.end();
			})

		}else if(req.url = '/todo.js'){
			fs.readFile('todo.js', function(err, data){
				res.writeHead(200, {'Content-Type': 'text/javascript'});
				res.write(data);
				res.end();
			})
			
		}
		//send404(res);

	}else if(req.method == "POST"){

	}
	else{ //if not a GET request, send 404 for now by default
		send404(res);
	}
});

server.listen(3000);
console.log('server running on port 3000');
*/

const app = require('express')();
const http = require('http').createServer(app);
const io = require('socket.io')(http);

app.get('/', function(req, res) {
	res.sendFile(__dirname + '/todo.html');
	console.log("/todo.html Grabed");
});

app.get('/todo.js', function(req, res) {
    res.sendFile(__dirname + '/todo.js');
	console.log("/todo.js Grabed");
});

http.listen(3000, function () {
    console.log("Listening on *:3000");
});