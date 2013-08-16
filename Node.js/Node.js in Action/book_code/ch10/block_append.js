extends layout

block title
  title Messages

block style
  link(
    rel="stylesheet",
    href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8/
    
  )

block append scripts
  script(src='https://ajax.googleapis.com/ajax/
  

block content
  count = 0
  each message in messages
    - count = count + 1
    script
      $(function() {
        $("#message_#{count}").dialog({
          height: 140,
          modal: true
        });
      });
    != 'div id="message_' + count + '"'
