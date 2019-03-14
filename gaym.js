var pjs = new PointJS(1720, 880, {backgroundColor: 'black'})
var game = pjs.game;
var key = pjs.keyControl;
key.initControl();
var brush = pjs.brush;
var b = false;

//pjs.system.initFullPage();

	
var back = game.newBackgroundObject(   { 
     x : 0, 
     y : 0, 
     w : 1720, 
     h : 880, 
     countX : 1, 
     countY : 1, 
     file : "fon.jpg", 
   });


var trash = game.newImageObject(   { 
     file : "trash.png", 
     x : 20, 
     y : 30, 
     w : 90, 
     h : 70, 
     //scale : 0.5, // уменьшить картинку в 2 раза, если не заданы ширина и высота
   });

var papka = game.newImageObject(   { 
     file : "papka.png", 
     x : 30, 
     y : 130, 
     w : 65, 
     h : 70, 
     //scale : 0.5, // уменьшить картинку в 2 раза, если не заданы ширина и высота
   });


var probel = game.newImageObject(   { 
     file : "probel.jpg", 
     x : 200, 
     y : 250, 
     w : 800, 
     h : 400, 
     //scale : 0.5, // уменьшить картинку в 2 раза, если не заданы ширина и высота
   });




game.newLoop('introduction', function () {

	back.draw();
	trash.draw();
	papka.draw();
	probel.draw();


	if (key.isDown('SPACE')) b = true;
    brush.drawTextLines({
  	lines : b ? ["Молодец"] : ["Доброго времени суток", "если видите текст", "нажмите пробел"] , 
  	x : 500,
 	y : 100, 
  	color : "white",
  	size : 30
});
    if (b){
    	probel.alpha = 0; 
    }

    brush.drawText({ 
   text : "Корзина", 
   x : 40, 
   y : 95, 
   color : "white", 
   size : 15 
  });


    brush.drawText({ 
   text : "Папка", 
   x : 41, 
   y : 195, 
   color : "white", 
   size : 15 
  });
    












	
}) // закончился ировой цикл myGame

game.setLoop('introduction');
game.start();
