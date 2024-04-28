package main

import (
	"fmt"
	"math"
)

func printTable(x, y float64) {
	fmt.Println("_____________________")
	if math.Abs(y) < 0.000001 {
		y = 0
	}
	if math.Abs(x) < 0.000001 {
		x = 0
	}
	fmt.Printf("%6.2f    |%11.2f\n", x, y) // красиво
}

func secondCircle(x float64) float64 {
	sqrtCheck := 4 - math.Pow(x, 2)
	if sqrtCheck >= 0 { // Попадаем в nan когда sqrt(0)
		return 2 - math.Sqrt(sqrtCheck)
	} else {
		return 2.0
	}
}

func main() {
	dx := 0.1
	xn := -3.0
	xk := 6.0
	fmt.Println("  x          y")
	for -3 <= xn && xn < -0.9 { // каждый while новая часть графика
		printTable(xn, -1*xn-2)
		xn += dx
	}
	for -0.9 <= xn && xn < 0 {
		printTable(xn, math.Sqrt(1-math.Pow(xn, 2))-1)
		xn += dx
	}
	for 0 <= xn && xn <= 2.1 {
		printTable(xn, secondCircle(xn))
		xn += dx
	}
	xn -= dx // в прошлый раз мы дошли до значения 2.1, но у нас разрывается график
	for 2 <= xn && xn <= 4.1 {
		printTable(xn, -1)
		xn += dx
	}
	for 4 <= xn && xn <= xk {
		printTable(xn, 0.5*xn-3)
		xn += dx
	}
}
