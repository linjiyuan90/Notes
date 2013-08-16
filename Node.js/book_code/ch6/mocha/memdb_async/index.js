var db = [];

exports.save = function(doc, cb){
  db.push(doc);
  if (cb) {
    setTimeout(function() {
      cb();
    }, 1000);
  }
};

exports.clear = function(){
  db = [];
};
