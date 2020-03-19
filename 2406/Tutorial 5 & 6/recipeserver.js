
//Database to store all recipe data
//This will give you 3 recipes to start with
let database = {
	"b0e347d5-9428-48e5-a277-2ec114fc05a0":{
		"ingredients":
		[
			{"name":"Crab","unit":"Tsp","amount":3},
			{"name":"Peas","unit":"Cup","amount":12},
			{"name":"Basil","unit":"Tbsp","amount":10},
			{"name":"Cumin","unit":"Liter","amount":3},
			{"name":"Salt","unit":"Tbsp","amount":1}
		],
		
		"name":"Boiled Crab with Peas",
		"preptime":"13",
		"cooktime":"78",
		"description":"A boring recipe using Crab and Peas",
		"id":"b0e347d5-9428-48e5-a277-2ec114fc05a0"
	},
	"04dcde4f-b1de-4f2b-b169-969594c82278":{
		"ingredients":
		[
			{"name":"Peanuts","unit":"Liter","amount":10},
			{"name":"Artichoke","unit":"Tsp","amount":3},
			{"name":"Basil","unit":"Cup","amount":11},
			{"name":"Sage","unit":"Grams","amount":13},
			{"name":"Pepper","unit":"Cup","amount":1}
		],
		
		"name":"Boiled Peanuts with Artichoke",
		"preptime":"73",
		"cooktime":"74",
		"description":"A exciting recipe using Peanuts and Artichoke",
		"id":"04dcde4f-b1de-4f2b-b169-969594c82278"
	},
	"b45bb7f9-51bc-47de-a4c3-fa564a241c27":{
		"ingredients":
		[
			{"name":"Lobster","unit":"Tsp","amount":14},
			{"name":"Brussel Sprouts","unit":"Liter","amount":14},
			{"name":"Sage","unit":"Tbsp","amount":3},
			{"name":"Thyme","unit":"Tbsp","amount":12},
			{"name":"Pepper","unit":"Tsp","amount":10},
			{"name":"Cumin","unit":"Tbsp","amount":11}
		],
			
		"name":"Spicy Lobster with Brussel Sprouts",
		"preptime":"86",
		"cooktime":"19",
		"description":"A tasty recipe using Lobster and Brussel Sprouts",
		"id":"b45bb7f9-51bc-47de-a4c3-fa564a241c27"
	}
}

const express = require('express');
let app = express();

app.use(express.static("public"));

//Start adding route handlers here

app.listen(3000);
console.log("Server listening at http://localhost:3000");