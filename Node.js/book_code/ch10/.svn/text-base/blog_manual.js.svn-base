function blogPage(entries) {
  var output = '<html>'
             + '<head>'
             + '<style type="text/css">'
             + '.entry_title { font-weight: bold; }'
             + '.entry_date { font-style: italic; }'
             + '.entry_body { margin-bottom: 1em; }'
             + '</style>'
             + '</head>'

             + '<body>';

  entries.map(function(entry) {
    output += '<div class="entry_title">' + entry.title + "</div>\n"
            + '<div class="entry_date">' + entry.date + "</div>\n"
            + '<div class="entry_body">' + entry.body + "</div>\n";
  });

  output += '</body></html>';

  return output;
}
