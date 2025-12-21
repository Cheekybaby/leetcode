func angleClock(hour int, minutes int) float64 {
    if hour == 12 {
        hour = 0
    }
    hr_angle := float64(hour * 30) + float64(minutes) / 2
    min_angle := float64(minutes * 6)
    
    angle := abs(min_angle - hr_angle)

    if angle > float64(180) {
        angle = float64(360) - angle
    }

    return angle
}
func abs(x float64) float64 {
    if x < float64(0) {
        return -x
    }
    return x
}