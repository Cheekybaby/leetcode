func maxBottlesDrunk(numBottles int, numExchange int) int {
    drank := 0
    for numBottles >= numExchange {
        drink := min(numBottles, numExchange)
        
        drank += drink
        
        numExchange += 1
        numBottles -= (drink - 1)
    }
    drank += (numBottles)

    return drank
}