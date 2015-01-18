var main = function() {
  $('.dropdown-toggle').click(function() {
    $('.dropdown-menu').toggle();
  });
  
  $('.arrow-next').click(function() {
    var currentSlide = $('.active-slide');
    var nextSlide = $('.active-slide').next();
    var currentDot = $('.active-dot');
    var nextDot = currentDot.next();
    
    if(nextSlide.length == 0) {
      nextSlide = $('.slide').first();
      nextDot = $('.dot').first();
    }
    
    currentSlide.fadeOut(600).removeClass('active-slide');
    nextSlide.fadeIn(600).addClass('active-slide');
    currentDot.removeClass('active-dot');
    nextDot.addClass('active-dot');
  });
  
  $('.arrow-prev').click(function() {
    var currentSlide = $('.active-slide');
    var prevSlide = $('.active-slide').prev();
    var currentDot = $('.active-dot');
    var prevDot = currentDot.prev();
    
    if(prevSlide.length == 0) {
      prevSlide = $('.slide').last();
      prevDot = $('.dot').last();
    }
    
    currentSlide.fadeOut(600).removeClass('active-slide');
    prevSlide.fadeIn(600).addClass('active-slide');
    currentDot.removeClass('active-dot');
    prevDot.addClass('active-dot');
  });
}
$(document).ready(main);
Dieses Board konnt ihr gleichzeitig bearbeiten. Rechts oben den Vornamen eingeben, dann ist klar, wer was geschrieben hat. 
Collaborate seamlessly on documents! This pad text is synchronized as you type, so that everyone viewing this page sees the same text. No need to press a save button. 
Create your own board and a (secret) name for it here: http://board.net . Pass it on to your colleagues with the share button.
Provided by http://ethify.org and green hosted by http://www.ALLMENDA.com Cloud Services.
