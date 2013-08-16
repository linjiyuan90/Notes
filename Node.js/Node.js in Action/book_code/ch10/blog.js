var fs = require('fs');
var http = require('http');

function getEntries() {
  var entries = [];
  var entriesRaw = fs.readFileSync('./entries.txt', 'utf8');

  entriesRaw = entriesRaw.split("---");

  entriesRaw.map(function(entryRaw) {
    var entry = {};
    var lines = entryRaw.split("\n");

    lines.map(function(line) {
      if (line.indexOf('title: ') === 0) {
        entry.title = line.replace('title: ', '');
      }
      else if (line.indexOf('date: ') === 0) {
        entry.date = line.replace('date: ', '');
      }
      else {
        entry.body = entry.body || '';
        entry.body += line;
      }
    });

    entries.push(entry);
  });

  return entries;
}

var entries = getEntries();
console.log(entries);
