const mongoose = require("mongoose");
const Schema = mongoose.Schema;

let userSchema = Schema({
	username: {type: String, required: true},
	password: {type: String, required: true},
	privacy: {type: Boolean, required: true},
	total_quizzes: {type: Number, default: 0},
	total_score: {type: Number, default: 0}
});

userSchema.statics.findID = function(arr, callback){
	this.find({'_id': {$in: arr}}, function(err, results){
		if(err){
			callback(err);
			return;
		}
		callback(null, results);		
	});
}

userSchema.statics.getUsers = function(callback){
	this.find().exec(callback);
}

module.exports = mongoose.model("User", userSchema);