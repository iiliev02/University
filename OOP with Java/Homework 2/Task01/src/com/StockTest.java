package com;

import java.util.Scanner;

public class StockTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String symbol, name;
        double previousClosingPrice, currentPrice;
        System.out.print("Enter a symbol of stock: ");
        symbol = input.nextLine();
        System.out.print("Enter a name of stock: ");
        name = input.nextLine();
        System.out.print("Enter a previous closing price of stock: ");
        previousClosingPrice = input.nextDouble();
        System.out.print("Enter a current price of stock: ");
        currentPrice = input.nextDouble();

        Stock stockA = new Stock(symbol, name);
        stockA.setPreviousClosingPrice(previousClosingPrice);
        stockA.setCurrentPrice(currentPrice);

        System.out.printf("Symbol of stock: %s\n Name of stock: %s\n Previous closing price: %.2f\n Current price: %.2f\n Percent: %.2f", stockA.getSymbol(), stockA.getName(), stockA.getPreviousClosingPrice(), stockA.getCurrentPrice(), stockA.changePercent());
    }
}
