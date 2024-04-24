## cpts-122-final

> [!CAUTION]  
> In the builds, the debug messages won't show, becuase the build isn't a debug build.
> Refer to the video for the messages.

### Playing Instructions
1. Find and download the file in "Builds".
2. Double-click the .exe file.
3. Use WASD to move and the mouse to look around.
4. Collect various items around the map.

### Collaborators
- Aryan Puthran (Section 6)
- Johnny Davis (Section 5)

### Link to Video
[INSERT]

### Test Cases
There are 5 different pickup types, these are our 5 test cases.<br>
Each item has it's own debug message and debug message color.
1. Skulls x2
2. Coins x2
3. Candles x1
4. Chandelier x1
5. Coffin x1

### Why Polymorphism Couldn't Happen
Since this project is super simple, it's hard to justofy a way to implement polymorphism,<br>
especially since all the functions have the same function. The printing of messages to the screen has parameters,<br>
but isn't overloaded. Our game instead heavily uses inheritance. SInce th behavior of classes don't need to change or<br>
be overidden, there is no use for polymorphism, and forcing it would do more harm than good.

### Class Structure
ACharacter < APerformer<br>
AActor < APickup < CoinPickup / SkullPickup / CandlePickup / ChandelierPickup / CoffinPickup
