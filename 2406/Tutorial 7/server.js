
/*
Card source: https://api.hearthstonejson.com/v1/25770/enUS/cards.json

Each card is a JS object
All have:
	id - string uniquely identifies the card
	artist - string indicating the name of the artist for the cards image
	cardClass - string indicating the class of the card
	set  - string indicating the set the card is from
	type - string indicating the type of the card
	text - string indicating card text
Some have:
	rarity - string indicating the rarity of the card
	mechanics - array of string indicating special mechanics
	
Routes:
	/cards - search all cards (query params: class, set, type, artist)
	/cards/:cardID - specific card with ID=:cardID
*/

//Set up the required data
let cardData = require("./cards.json");
let cards = {}; //Stores all of the cards, key=id
//Below objects are used to define acceptable query parameter values
let artists = {};
let classes = {};
let sets = {} 
let types = {}

cardData.forEach(card => {
	cards[card.id] = card;
	artists[card.artist.toUpperCase()] = 1;
	classes[card.cardClass.toUpperCase()] = 1;
	sets[card.set.toUpperCase()] = 1;
	types[card.type.toUpperCase()] = 1;
});

//Create express app
const express = require('express');
let app = express();
app.set('view engine', 'pug');


//Set up the routes
app.get("/cards", logRequest, parseQuery, getCards, sendCardList);
app.get("/cards/:cardID", sendSingleCard);

//Log some information about the request
function logRequest(req, res, next){
	console.log("Method: " + req.method);
	console.log("URL: " + req.url);
	console.log(req.query);
	next();
}

//Parses the query string data and sets up req.searchParams
//req.searchParams is then used in the getCards function
function parseQuery(req, res, next){
	req.searchParams = {};
	
	if(req.query.class && classes.hasOwnProperty(req.query.class.toUpperCase())){
		req.searchParams.class = req.query.class.toUpperCase();
		console.log("Cards must have class: " + req.query.class.toUpperCase());
	}
	
	if(req.query.set && sets.hasOwnProperty(req.query.set.toUpperCase())){
		req.searchParams.set = req.query.set.toUpperCase();
		console.log("Cards must have set: " + req.query.set.toUpperCase());
	}
	
	console.log(req.query.type);
	if(req.query.type && types.hasOwnProperty(req.query.type.toUpperCase())){
		req.searchParams.type = req.query.type.toUpperCase();
		console.log("Cards must have type: " + req.query.type.toUpperCase());
	}
	
	if(req.query.artist && artists.hasOwnProperty(req.query.artist.toUpperCase())){
		req.searchParams.artist = req.query.artist.toUpperCase();
		console.log("Cards must have artist: " + req.query.artist.toUpperCase());
	}
	
	next();
}

//Adds a res.cards property that is an array of all cards matching the request query
function getCards(req, res, next){
	res.cards = [];
	//For each card, if it matches, add it to res.cards
	for(let id in cards){
		let card = cards[id];
		let match = ((!req.searchParams.artist) || (req.searchParams.artist == card.artist.toUpperCase())) && ((!req.searchParams.type) || (req.searchParams.type == card.type.toUpperCase())) && ((!req.searchParams.set) || (req.searchParams.set == card.set.toUpperCase())) && ((!req.searchParams.class) || (req.searchParams.class == card.cardClass.toUpperCase()));
		
		if(match){
			res.cards.push(card);
		}
	};
	console.log("Matched " + res.cards.length + " cards.");
	next();
}

/*
 Modify this function. You should use res.format to send JSON
 data when requested, or use a template engine to generate
 HTML to send as a response if HTML is requested. If any other
 format is requested, you can choose to send HTML or JSON by
 default, or send an error indicating that the requested type
 of data is not valid.
*/
function sendCardList(req, res, next){
	let responseCards = res.cards;
	res.format({
		'text/html': function(){
			res.render('pages/cards', {responseCards: responseCards});
			
		},
		'application/json': function(){

			res.send(responseCards);
		},
		'default': function(){
			res.render('pages/cards', {responseCards: responseCards});
		}
	});

}

/*
 Modify this function. You should use res.format to send JSON
 data when requested, or use a template engine to generate
 HTML to send as a response if HTML is requested. If any other
 format is requested, you can choose to send HTML or JSON by
 default, or send an error indicating that the requested type
 of data is not valid.
*/
function sendSingleCard(req, res, next){
	let cardID = req.params.cardID;
	console.log(cardID);
	if(cards.hasOwnProperty(cardID)){
		let responseCard = cards[cardID];
		res.format({
			'text/html': function(){
				res.render('pages/card', {responseCard: responseCard});
				
			},
			'application/json': function(){
	
				res.send(responseCard);
			},
			'default': function(){
				res.render('pages/card', {responseCard: responseCard});
			}
		});
	}else{
		res.status(404).send("Invalid card ID.");
	}
}

//Start server
app.listen(3000);
console.log("Server listening at http://localhost:3000");