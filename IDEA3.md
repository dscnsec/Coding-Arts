# Phase 2 Questions

## Problem Statement 7:
There will be a sports competition on this upcoming Republic day in Ravi's school. There will be a lot of different sports available for participating. But Ravi is more inclined towards the one which requires a team to participate.

For this year Ravi has been appointed as the referee of two particular sports named duo relay race & trio relay race.

To make the races more optimal and neutral the school authority has come up with an idea of equivalent team distribution. The teams will be created with student of same height only.

For an example, if the students of a particular class having heights as = {160,170,180,160,170,180}

Then team A will be of students with height 160, team B will be of students with height 170 and so on. Given that, height of a team will be unique among all the teams.
But the main problem arises when a student’s height matches with no one, as a result he/she can’t participate.

As a referee Ravi has to find this type of students so that he can take special care of them.
Can you help Ravi?

N.B: Trio relay race consists a team of three same height players and Duo relay race consists a team of two same height players.
It is always true that there will always be only one student whose height will match with no one.


n - number of students in duo race
m - number of students in trio race
 
## Sample testcase for problem statement 7 :

## Input 1

     5
     165 167 174 167 165
     10
     163 164 165 163 165 168 163 164 165 164


## Output 1

     174 168

## Input 2

    3
    170 171 170
    1
    175


## Output 2

     171 175
  
      
  
   
## Problem Statement 8:
Isha shared her songs playlist to her friend Dipti.
There are n songs in that playlist, such that only next songs
will be played by clicking on next button as next song is linked with current song
(note:- previous button does not exist i.e, previous songs can't be played)
 eg:- song(1)->song(2)>song(3)->....->song(n-1)->song(n) if this is isha's song playlist
 then songs will be played in this order song(1), song(2), song(3) upto song(n).
 
 But, Dipti didn't like the order and decided to change the order.
 New order will be such that songs will be played equidistant from front and end,
 song(1) is played then on clicking next button, song(n) will be played
 then song(2) is played then song(n-1) will be played.
 New order of the playlist will be,
 song(1)->song(n)->song(2)->song(n-1)-song(3)-song(n-2)...
 Playlist will always start with song(1).
 your task is to help Dipti in reordering the playlist.
 
 (Note:-Data structure used will be linked list , You must do this in-place without
 altering the node's values)
### input pattern 
### line 1:
Number of songs n ( n>=1 )
### line 2:
Total n space seprated integers representing songs. 

### output pattern 
space seprated integer of reordered playslist 
### Sample testcase for problem statement 8 :

  ### Input1: 
  6
  1 2 3 4 5 6
    
  ### output1 : 1 6 2 5 3 4
   
   ### Input2:
   3
   1 2 3 
   
   ### output2: 1 3 2 
    
   
   
      
