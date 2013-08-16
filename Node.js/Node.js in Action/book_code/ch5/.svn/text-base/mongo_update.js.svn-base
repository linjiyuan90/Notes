var mongodb = require('mongodb')
  , server = new mongodb.Server('127.0.0.1', 27017, {});

var client = new mongodb.Db('mtest', server);

client.open(function(err) {
  client.collection('test_insert', function(err, collection) {
    if (err) throw err;

    collection.insert(
      {"title": "I like cake", "body": "It is quite good."},
      {safe: true},
      function(err, documents) {
        if (err) throw err;
        console.log('Document ID is: ' + documents[0]._id);
        var documentId = documents[0]._id.toString();
        var _id = new client.bson_serializer
                            .ObjectID(documentId);
        collection.update(
          {_id: _id},
          {$set: {"title": "I ate too much cake"}},
          {safe: true},
          function(err) {
            if (err) throw err;
            console.log('Updated.');
          }
        );
      }
    );
  });
});
