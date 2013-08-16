var redis = require('redis'),
    client = redis.createClient(6379, '127.0.0.1');

client.on('error', function (err) {
    console.log('Error ' + err);
});

client.hset('camping', 'shelter', '2-person tent', redis.print);
client.hset('camping', 'cooking', 'campstove', redis.print);

client.hget('camping', 'cooking', function(err, value) {
  console.log('Will be cooking with: ' + value);
});

client.hkeys('camping', function(err, keys) {
  if (err) throw err;
  keys.forEach(function(key, i) {
    console.log('  ' + key);
  });
});
