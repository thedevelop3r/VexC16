# VexC16
The code and resources for Spring-Ford High School's Team C Vex Robot

Competition Code (Built on Latest Version)
-----------------------------------------------

  1) Runs the autonomous task for the number of seconds defined in the pragma
  
  2) Following autonomous mode, runs the main task for the number of seconds defined in the pragma

Version 2_3_16
-----------------------------------------------

Controls:

      Driving:
      
        default control mode (no Right trigger depressed)
        
          turn: Left stick Left & Right
          
          move: (forward & backward), Left stick Up & Down
          
        tank control mode (Lower Right trigger depressed)
        
          move: left wheel, Left stick Up & Down
          
          move: right wheel, Right stick Up & Down
          
        accelerometer control mode (Upper Right trigger depressed)
        
          turn: tilt Left and Right
          
          move: (forward & backward), tilt Forward and Back
          
      Claw Movement:
      
        claw up: left stick Up
        
        claw down: left stick Down
        
      Toggle modes:
      
        run autonomous sequence: press Button 7D
        
        switch Forward Direction: press Button 8D
        
    Autonomous Documentation:
    
      The goal of the current autonomous implementation is to score with a set of pre-loaded balls in the low goal.
      This is accomplished by orienting the robot towards the goal, driving to it, and dumping the pre-loaded balls.
      
      Orienting the Robot:
      
        1) FACE THE NET
        
      Program Overview:
        
        1) run macro to deliver balls from given position
        
        2) wait for user control period
      
