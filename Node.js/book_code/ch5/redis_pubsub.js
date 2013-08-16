var redis = require('redis')
  , clientA = redis.createClient() 
  , clientB = redis.createClient();

clientA.on('message', function(channel, message) { 
  console.log('Client A got message from channel %s: %s',
    channel,
    message
  );
});

clientA.on('subscribe', function(channel, count) { 
  clientB.publish('main_chat_room', 'Hello world!'); 
});

clientA.subscribe('main_chat_room');