package com;

public class Stock {
    private String symbol;
    private String name;
    private double previousClosingPrice;
    private double currentPrice;

    public Stock(String symbol, String name) {
        this.symbol = symbol != null ? symbol : "No symbol";
        this.name = name != null ? name : "No name";
        setPreviousClosingPrice(1.0);
        setCurrentPrice(1.0);
    }

    public String getSymbol() {
        return this.symbol;
    }

    public String getName() {
        return this.name;
    }

    public double getPreviousClosingPrice() {
        return this.previousClosingPrice;
    }

    public double getCurrentPrice() {
        return this.currentPrice;
    }

    public void setPreviousClosingPrice(double price) {
        this.previousClosingPrice = price > 0.0 ? price : 1.0;
    }

    public void setCurrentPrice(double price) {
        this.currentPrice = price > 0.0 ? price : 1.0;
    }

    public double changePercent() {
        return (100 * (this.currentPrice - this.previousClosingPrice)) / this.previousClosingPrice;
    }
}
