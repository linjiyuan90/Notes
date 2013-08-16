var memdb = require('..');
var assert = require('assert');

describe('memdb', function(){
  beforeEach(function(){
    memdb.clear(); 
  })

  describe('.save(doc)', function(){
    it('should save the document', function(done){
      var pet = { name: 'Tobi' };
      memdb.save(pet, function(){ 
        done(); 
      });
    });
  });
})
