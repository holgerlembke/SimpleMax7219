SimpleMax7219
=============

### What?

    SimpleMax7219 is another max7219 matrix driver for one matrix only.
    
### Design goal
    
    Do not use spi, so any ports will go. 
    
    This is slow and really ressource independant. 
    
### Usage    

    Create a object 
    
    ```
    simplemax7219 disp(wemosD8,wemosD7,wemosD6); // data clock load
    ```
    
    Call begin() to init the object
    
    ```
    disp.begin();
    ```
    
    Use it.

### Why?

    Designed for development board of
    Internet of Things (IoT) mit dem ESP8266 und Arduino
    KWH96BU
    Beginn: Mo. 06.02.2017, 08:30 Uhr 

### License

This library is licensed under the MIT license. Use it! Fix it! Develop it!

