#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <math.h>
#include "Storage.h"
#include "Section.h"
#include "myFunctions.h"
using namespace std;

void removeProductFromListProducts(vector<Storage>& storageProducts, vector<Storage> products)
{
	for (size_t i = 0; i < products.size(); i++)
	{
		for (size_t j = 0; j < storageProducts.size(); j++)
		{
			if (strcmp(products[i].getProductName(), storageProducts[j].getProductName()) == 0
				&& products[i].getExpirationDate() == storageProducts[j].getExpirationDate()
				&& products[i].getEntranceDate() == storageProducts[j].getEntranceDate()
				&& strcmp(products[i].getProducer(), storageProducts[j].getProducer()) == 0
				&& strcmp(products[i].getUnit(), storageProducts[j].getUnit()) == 0
				&& products[i].getAvailableQuantity() == storageProducts[j].getAvailableQuantity()
				&& products[i].getLocation() == storageProducts[j].getLocation()
				&& strcmp(products[i].getComment(), storageProducts[j].getComment()) == 0)
			{
				storageProducts.erase(storageProducts.begin() + j);
			}
		}
	}
}

void addProduct(Section*& sections, vector<Storage>& storageProducts, Storage& product, int& count, bool& isAdd)
{
	float quan = product.getAvailableQuantity();
	if (quan <= CAPACITY_QUANTITY)
	{
		if (!existProduct(sections, product, count))
		{
			for (size_t i = 0; i < count; i++)
			{
				bool addProd = false;
				for (size_t j = 0; j < CAPACITY_SHELF; j += 2)
				{
					if (sections[i].getShelf()[j].getBusySpace() == 0.0)
					{
						sections[i].getShelf()[j].setBusyCells(product);
						string shelf = to_string(j + 1);
						string numeric = "1-" + to_string(sections[i].getShelf()[j].getCells().size());
						Location newLoc = Location(i + 1, shelf, numeric);
						product.setLocation(newLoc);
						sections[i].getShelf()[j].pushProduct(product);
						storageProducts.push_back(product);
						addProd = true;
						break;
					}
				}
				if (!addProd)
				{
					if (i + 1 >= count)
					{
						count++;
					}
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			int posShelf = 0;
			int posSection = 0;
			bool isHere = false;
			for (size_t i = 0; i < count; i++)
			{
				for (size_t j = 0; j < CAPACITY_SHELF; j += 2)
				{
					for (size_t z = 0; z < sections[i].getShelf()[j].getProducts().size(); z++)
					{
						if (strcmp(sections[i].getShelf()[j].getProducts()[z].getProductName(), product.getProductName()) == 0)
						{
							posSection = i;
							posShelf = j;
							isHere = true;
							break;
						}
					}
					if (isHere)
					{
						break;
					}
				}
			}
			if (isHere)
			{
				float freeSpace = (2 * CAPACITY_QUANTITY) - sections[posSection].getShelf()[posShelf].getBusySpace() - sections[posSection].getShelf()[posShelf + 1].getBusySpace();
				if (freeSpace >= product.getAvailableQuantity())
				{
					if (sameProduct(sections, product, posSection, posShelf))
					{
						vector<Storage> rearrangeProducts;
						rearrange(sections, posSection, posShelf, rearrangeProducts);
						clearShelfs(sections, posSection, posShelf);
						for (size_t i = 0; i < rearrangeProducts.size(); i++)
						{
							if (rearrangeProducts[i].getExpirationDate() == product.getExpirationDate()
								&& strcmp(rearrangeProducts[i].getProducer(), product.getProducer()) == 0
								&& strcmp(rearrangeProducts[i].getComment(), product.getComment()) == 0)
							{
								rearrangeProducts[i].setAvailableQuantity(rearrangeProducts[i].getAvailableQuantity() + product.getAvailableQuantity());
							}
						}
						for (size_t i = 0; i < rearrangeProducts.size(); i++)
						{
							float avaiQuan = rearrangeProducts[i].getAvailableQuantity();
							if (avaiQuan <= CAPACITY_QUANTITY)
							{
								if (sections[posSection].getShelf()[posShelf].getBusySpace() == 0)
								{
									sections[posSection].getShelf()[posShelf].setBusyCells(rearrangeProducts[i]);
									string shelf = to_string(posShelf + 1);
									string numeric = "1-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size());
									Location newLoc = Location(posSection + 1, shelf, numeric);
									rearrangeProducts[i].setLocation(newLoc);
									sections[posSection].getShelf()[posShelf].pushProduct(rearrangeProducts[i]);
									newLocation(storageProducts, rearrangeProducts[i]);
								}
								else
								{
									if (sections[posSection].getShelf()[posShelf].getFreeSpace() >= rearrangeProducts[i].getAvailableQuantity())
									{
										Storage copyProduct = rearrangeProducts[i];
										int countPreviousCells = sections[posSection].getShelf()[posShelf].getCells().size();
										if (sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity() != 0)
										{
											copyProduct.setAvailableQuantity(rearrangeProducts[i].getAvailableQuantity() - sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity());
											sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].setCellCapacity(50.0, 0.0);
										}
										if (sections[posSection].getShelf()[posShelf].getCells().size() < 4)
										{
											sections[posSection].getShelf()[posShelf].setBusyCells(copyProduct);
										}
										else
										{
											sections[posSection].getShelf()[posShelf].getCells()[sections[posSection].getShelf()[posShelf].getCells().size() - 1].setCellCapacity(50.0, 0.0);
										}
										string shelf = to_string(posShelf + 1);
										string numeric = to_string(countPreviousCells) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size());
										Location newLoc = Location(posSection + 1, shelf, numeric);
										rearrangeProducts[i].setLocation(newLoc);
										sections[posSection].getShelf()[posShelf].pushProduct(rearrangeProducts[i]);
										newLocation(storageProducts, rearrangeProducts[i]);
									}
									else if (sections[posSection].getShelf()[posShelf].getFreeSpace() == 0.0)
									{
										if (sections[posSection].getShelf()[posShelf + 1].getBusySpace() == 0.0)
										{
											sections[posSection].getShelf()[posShelf + 1].setBusyCells(rearrangeProducts[i]);
											string shelf = to_string(posShelf + 2);
											string numeric = to_string(sections[posSection].getShelf()[posShelf].getCells().size() + 1) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size() + sections[posSection].getShelf()[posShelf + 1].getCells().size());
											Location newLoc = Location(posSection + 1, shelf, numeric);
											rearrangeProducts[i].setLocation(newLoc);
											sections[posSection].getShelf()[posShelf + 1].pushProduct(rearrangeProducts[i]);
											newLocation(storageProducts, rearrangeProducts[i]);
										}
										else
										{
											if (sections[posSection].getShelf()[posShelf + 1].getFreeSpace() >= rearrangeProducts[i].getAvailableQuantity())
											{
												int countPreviousCells = sections[posSection].getShelf()[posShelf + 1].getCells().size();
												Storage copyProduct = rearrangeProducts[i];
												if (sections[posSection].getShelf()[posShelf + 1].getCells()[countPreviousCells - 1].getFreeCapacity() != 0)
												{
													copyProduct.setAvailableQuantity(rearrangeProducts[i].getAvailableQuantity() - sections[posSection].getShelf()[posShelf + 1].getCells()[countPreviousCells - 1].getFreeCapacity());
													sections[posSection].getShelf()[posShelf + 1].getCells()[countPreviousCells - 1].setCellCapacity(50.0, 0.0);
												}
												if (sections[posSection].getShelf()[posShelf + 1].getCells().size() < 4)
												{
													sections[posSection].getShelf()[posShelf + 1].setBusyCells(copyProduct);
												}
												else
												{
													sections[posSection].getShelf()[posShelf + 1].getCells()[sections[posSection].getShelf()[posShelf + 1].getCells().size() - 1].setCellCapacity(50.0, 0.0);
												}
												string shelf = to_string(posShelf + 2);
												string numeric = to_string(sections[posSection].getShelf()[posShelf].getCells().size() + countPreviousCells) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size() + sections[posSection].getShelf()[posShelf + 1].getCells().size());
												Location newLoc = Location(posSection + 1, shelf, numeric);
												rearrangeProducts[i].setLocation(newLoc);
												sections[posSection].getShelf()[posShelf + 1].pushProduct(rearrangeProducts[i]);
												newLocation(storageProducts, rearrangeProducts[i]);
											}
											else
											{
												printMessages(4);
												isAdd = false;
											}
										}
									}
									else
									{
										Storage firstProduct = rearrangeProducts[i];
										firstProduct.setAvailableQuantity(sections[posSection].getShelf()[posShelf].getFreeSpace());
										Storage secondProduct = rearrangeProducts[i];
										secondProduct.setAvailableQuantity(rearrangeProducts[i].getAvailableQuantity() - sections[posSection].getShelf()[posShelf].getFreeSpace());
										Storage copyProduct = firstProduct;
										int countPreviousCells = sections[posSection].getShelf()[posShelf].getCells().size();
										if (sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity() != 0)
										{
											copyProduct.setAvailableQuantity(firstProduct.getAvailableQuantity() - sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity());
											sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].setCellCapacity(50.0, 0.0);
										}
										if (sections[posSection].getShelf()[posShelf].getCells().size() < 4)
										{
											sections[posSection].getShelf()[posShelf].setBusyCells(copyProduct);
										}
										else
										{
											sections[posSection].getShelf()[posShelf].getCells()[sections[posSection].getShelf()[posShelf].getCells().size() - 1].setCellCapacity(50.0, 0.0);
										}
										sections[posSection].getShelf()[posShelf + 1].setBusyCells(secondProduct);
										string shelf = to_string(posShelf + 1) + "-" + to_string(posShelf + 2);
										string numeric = to_string(countPreviousCells) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size() + sections[posSection].getShelf()[posShelf + 1].getCells().size());
										Location newLoc = Location(posSection + 1, shelf, numeric);
										firstProduct.setLocation(newLoc);
										secondProduct.setLocation(newLoc);
										rearrangeProducts[i].setLocation(newLoc);
										sections[posSection].getShelf()[posShelf].pushProduct(firstProduct);
										sections[posSection].getShelf()[posShelf + 1].pushProduct(secondProduct);
										newLocation(storageProducts, rearrangeProducts[i]);
									}
								}
							}
							else if (avaiQuan > CAPACITY_QUANTITY && avaiQuan <= 2 * CAPACITY_QUANTITY)
							{
								Storage firstProduct = rearrangeProducts[i];
								Storage secondProduct = rearrangeProducts[i];
								firstProduct.setAvailableQuantity(CAPACITY_QUANTITY);
								secondProduct.setAvailableQuantity(rearrangeProducts[i].getAvailableQuantity() - CAPACITY_QUANTITY);
								sections[posSection].getShelf()[posShelf].setBusyCells(firstProduct);
								sections[posSection].getShelf()[posShelf + 1].setBusyCells(secondProduct);
								string shelf = to_string(posShelf + 1) + "-" + to_string(posShelf + 2);
								string numeric = "1-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size() + sections[posSection].getShelf()[posShelf + 1].getCells().size());
								Location newLoc = Location(posSection + 1, shelf, numeric);
								firstProduct.setLocation(newLoc);
								secondProduct.setLocation(newLoc);
								rearrangeProducts[i].setLocation(newLoc);
								sections[posSection].getShelf()[posShelf].pushProduct(firstProduct);
								sections[posSection].getShelf()[posShelf + 1].pushProduct(secondProduct);
								newLocation(storageProducts, rearrangeProducts[i]);
							}
						}
					}
					else
					{
						if (sections[posSection].getShelf()[posShelf].getFreeSpace() >= product.getAvailableQuantity())
						{
							Storage copyProduct = product;
							int countPreviousCells = sections[posSection].getShelf()[posShelf].getCells().size();
							if (sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity() != 0)
							{
								copyProduct.setAvailableQuantity(product.getAvailableQuantity() - sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity());
								sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].setCellCapacity(50.0, 0.0);
							}
							if (sections[posSection].getShelf()[posShelf].getCells().size() < 4)
							{
								sections[posSection].getShelf()[posShelf].setBusyCells(copyProduct);
							}
							else
							{
								sections[posSection].getShelf()[posShelf].getCells()[sections[posSection].getShelf()[posShelf].getCells().size() - 1].setCellCapacity(50.0, 0.0);
							}
							string shelf = to_string(posShelf + 1);
							string numeric = to_string(countPreviousCells) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size());
							Location newLoc = Location(posSection + 1, shelf, numeric);
							product.setLocation(newLoc);
							sections[posSection].getShelf()[posShelf].pushProduct(product);
							storageProducts.push_back(product);
						}
						else if (sections[posSection].getShelf()[posShelf].getFreeSpace() == 0.0)
						{
							if (sections[posSection].getShelf()[posShelf + 1].getBusySpace() == 0)
							{
								sections[posSection].getShelf()[posShelf + 1].setBusyCells(product);
								string shelf = to_string(posShelf + 2);
								string numeric = to_string(sections[posSection].getShelf()[posShelf].getCells().size() + 1) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size() + sections[posSection].getShelf()[posShelf + 1].getCells().size());
								Location newLoc = Location(posSection + 1, shelf, numeric);
								product.setLocation(newLoc);
								sections[posSection].getShelf()[posShelf + 1].pushProduct(product);
								storageProducts.push_back(product);
							}
							else
							{
								if (sections[posSection].getShelf()[posShelf + 1].getFreeSpace() >= product.getAvailableQuantity())
								{
									int countPreviousCells = sections[posSection].getShelf()[posShelf + 1].getCells().size();
									Storage copyProduct = product;
									if (sections[posSection].getShelf()[posShelf + 1].getCells()[countPreviousCells - 1].getFreeCapacity() != 0)
									{
										copyProduct.setAvailableQuantity(product.getAvailableQuantity() - sections[posSection].getShelf()[posShelf + 1].getCells()[countPreviousCells - 1].getFreeCapacity());
										sections[posSection].getShelf()[posShelf + 1].getCells()[countPreviousCells - 1].setCellCapacity(50.0, 0.0);
									}
									if (sections[posSection].getShelf()[posShelf + 1].getCells().size() < 4)
									{
										sections[posSection].getShelf()[posShelf + 1].setBusyCells(copyProduct);
									}
									else
									{
										sections[posSection].getShelf()[posShelf + 1].getCells()[sections[posSection].getShelf()[posShelf + 1].getCells().size() - 1].setCellCapacity(50.0, 0.0);
									}
									string shelf = to_string(posShelf + 2);
									string numeric = to_string(sections[posSection].getShelf()[posShelf].getCells().size() + countPreviousCells) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size() + sections[posSection].getShelf()[posShelf + 1].getCells().size());
									Location newLoc = Location(posSection + 1, shelf, numeric);
									product.setLocation(newLoc);
									sections[posSection].getShelf()[posShelf + 1].pushProduct(product);
									storageProducts.push_back(product);
								}
								else
								{
									printMessages(4);
									isAdd = false;
								}
							}
						}
						else
						{
							Storage firstProduct = product;
							firstProduct.setAvailableQuantity(sections[posSection].getShelf()[posShelf].getFreeSpace());
							Storage secondProduct = product;
							secondProduct.setAvailableQuantity(product.getAvailableQuantity() - sections[posSection].getShelf()[posShelf].getFreeSpace());

							Storage copyProduct = firstProduct;
							int countPreviousCells = sections[posSection].getShelf()[posShelf].getCells().size();
							if (sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity() != 0)
							{
								copyProduct.setAvailableQuantity(firstProduct.getAvailableQuantity() - sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity());
								sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].setCellCapacity(50.0, 0.0);
							}
							if (sections[posSection].getShelf()[posShelf].getCells().size() < 4)
							{
								sections[posSection].getShelf()[posShelf].setBusyCells(copyProduct);
							}
							else
							{
								sections[posSection].getShelf()[posShelf].getCells()[sections[posSection].getShelf()[posShelf].getCells().size() - 1].setCellCapacity(50.0, 0.0);
							}

							sections[posSection].getShelf()[posShelf + 1].setBusyCells(secondProduct);
							string shelf = to_string(posShelf + 1) + "-" + to_string(posShelf + 2);
							string numeric = to_string(countPreviousCells) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size() + sections[posSection].getShelf()[posShelf + 1].getCells().size());
							Location newLoc = Location(posSection + 1, shelf, numeric);
							firstProduct.setLocation(newLoc);
							secondProduct.setLocation(newLoc);
							product.setLocation(newLoc);
							sections[posSection].getShelf()[posShelf].pushProduct(firstProduct);
							sections[posSection].getShelf()[posShelf + 1].pushProduct(secondProduct);
							storageProducts.push_back(product);
						}
					}
				}
				else
				{
					printMessages(4);
					isAdd = false;
				}
			}
		}
	}
	else if (quan > CAPACITY_QUANTITY && quan <= 2 * CAPACITY_QUANTITY)
	{
		if (!existProduct(sections, product, count))
		{
			for (size_t i = 0; i < count; i++)
			{
				bool addProd = false;
				for (size_t j = 0; j < CAPACITY_SHELF; j += 2)
				{
					if (sections[i].getShelf()[j].getBusySpace() == 0)
					{
						Storage firstProduct = product;
						Storage secondProduct = product;
						firstProduct.setAvailableQuantity(CAPACITY_QUANTITY);
						secondProduct.setAvailableQuantity(product.getAvailableQuantity() - CAPACITY_QUANTITY);
						sections[i].getShelf()[j].setBusyCells(firstProduct);
						sections[i].getShelf()[j + 1].setBusyCells(secondProduct);
						string shelf = to_string(j + 1) + "-" + to_string(j + 2);
						string numeric = "1-" + to_string(sections[i].getShelf()[j].getCells().size() + sections[i].getShelf()[j + 1].getCells().size());
						Location newLoc = Location(i + 1, shelf, numeric);
						firstProduct.setLocation(newLoc);
						secondProduct.setLocation(newLoc);
						product.setLocation(newLoc);
						sections[i].getShelf()[j].pushProduct(firstProduct);
						sections[i].getShelf()[j + 1].pushProduct(secondProduct);
						storageProducts.push_back(product);
						addProd = true;
						break;
					}
				}
				if (!addProd)
				{
					if (i + 1 >= count)
					{
						count++;
					}
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			int posShelf = 0;
			int posSection = 0;
			bool isHere = false;
			for (size_t i = 0; i < count; i++)
			{
				for (size_t j = 0; j < CAPACITY_SHELF; j += 2)
				{
					for (size_t z = 0; z < sections[i].getShelf()[j].getProducts().size(); z++)
					{
						if (strcmp(sections[i].getShelf()[j].getProducts()[z].getProductName(), product.getProductName()) == 0)
						{
							posSection = i;
							posShelf = j;
							isHere = true;
							break;
						}
					}
					if (isHere)
					{
						break;
					}
				}
			}
			float freeSpace = (2 * CAPACITY_QUANTITY) - sections[posSection].getShelf()[posShelf].getBusySpace() - sections[posSection].getShelf()[posShelf + 1].getBusySpace();
			if (freeSpace >= product.getAvailableQuantity())
			{
				Storage firstProduct = product;
				firstProduct.setAvailableQuantity(sections[posSection].getShelf()[posShelf].getFreeSpace());
				Storage secondProduct = product;
				secondProduct.setAvailableQuantity(product.getAvailableQuantity() - sections[posSection].getShelf()[posShelf].getFreeSpace());
				Storage copyProduct = firstProduct;
				int countPreviousCells = sections[posSection].getShelf()[posShelf].getCells().size();
				if (sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity() != 0)
				{
					copyProduct.setAvailableQuantity(firstProduct.getAvailableQuantity() - sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity());
					sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].setCellCapacity(50.0, 0.0);
				}
				if (sections[posSection].getShelf()[posShelf].getCells().size() < 4)
				{
					sections[posSection].getShelf()[posShelf].setBusyCells(copyProduct);
				}
				else
				{
					sections[posSection].getShelf()[posShelf].getCells()[sections[posSection].getShelf()[posShelf].getCells().size() - 1].setCellCapacity(50.0, 0.0);
				}
				sections[posSection].getShelf()[posShelf + 1].setBusyCells(secondProduct);
				string shelf = to_string(posShelf + 1) + "-" + to_string(posShelf + 2);
				string numeric = to_string(countPreviousCells) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size() + sections[posSection].getShelf()[posShelf + 1].getCells().size());
				Location newLoc = Location(posSection + 1, shelf, numeric);
				firstProduct.setLocation(newLoc);
				secondProduct.setLocation(newLoc);
				product.setLocation(newLoc);
				sections[posSection].getShelf()[posShelf].pushProduct(firstProduct);
				sections[posSection].getShelf()[posShelf + 1].pushProduct(secondProduct);
				storageProducts.push_back(product);
			}
			else
			{
				printMessages(4);
				isAdd = false;
			}
		}
	}
}

void addLog(vector<string>& logs, string systemCommand, string productName, string unit, float availableQuantity)
{
	Date today = receiveToday();
	string date = to_string(today.getYear()) + "-" + to_string(today.getMonth()) + "-" + to_string(today.getDate());
	string log = date + "->" + systemCommand + "->" + productName + "->" + unit + "->" + to_string(roundNum(availableQuantity));
	logs.push_back(log);
}

void addGetProduct(Section*& sections, vector<Storage>& storageProducts, Storage product, int posSection, int posShelf)
{
	float avaiQuan = product.getAvailableQuantity();
	if (avaiQuan <= CAPACITY_QUANTITY)
	{
		if (sections[posSection].getShelf()[posShelf].getBusySpace() == 0)
		{
			sections[posSection].getShelf()[posShelf].setBusyCells(product);
			string shelf = to_string(posShelf + 1);
			string numeric = "1-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size());
			Location newLoc = Location(posSection + 1, shelf, numeric);
			product.setLocation(newLoc);
			sections[posSection].getShelf()[posShelf].pushProduct(product);
			storageProducts.push_back(product);
		}
		else
		{
			if (sections[posSection].getShelf()[posShelf].getFreeSpace() >= product.getAvailableQuantity())
			{
				Storage copyProduct = product;
				int countPreviousCells = sections[posSection].getShelf()[posShelf].getCells().size();
				if (sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity() != 0)
				{
					copyProduct.setAvailableQuantity(product.getAvailableQuantity() - sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity());
					sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].setCellCapacity(50.0, 0.0);
				}
				if (sections[posSection].getShelf()[posShelf].getCells().size() < 4)
				{
					sections[posSection].getShelf()[posShelf].setBusyCells(copyProduct);
				}
				else
				{
					sections[posSection].getShelf()[posShelf].getCells()[sections[posSection].getShelf()[posShelf].getCells().size() - 1].setCellCapacity(50.0, 0.0);
				}
				string shelf = to_string(posShelf + 1);
				string numeric = to_string(countPreviousCells) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size());
				Location newLoc = Location(posSection + 1, shelf, numeric);
				product.setLocation(newLoc);
				sections[posSection].getShelf()[posShelf].pushProduct(product);
				storageProducts.push_back(product);
			}
			else if (sections[posSection].getShelf()[posShelf].getFreeSpace() == 0.0)
			{
				if (sections[posSection].getShelf()[posShelf + 1].getBusySpace() == 0.0)
				{
					sections[posSection].getShelf()[posShelf + 1].setBusyCells(product);
					string shelf = to_string(posShelf + 2);
					string numeric = to_string(sections[posSection].getShelf()[posShelf].getCells().size() + 1) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size() + sections[posSection].getShelf()[posShelf + 1].getCells().size());
					Location newLoc = Location(posSection + 1, shelf, numeric);
					product.setLocation(newLoc);
					sections[posSection].getShelf()[posShelf + 1].pushProduct(product);
					storageProducts.push_back(product);
				}
				else
				{
					if (sections[posSection].getShelf()[posShelf + 1].getFreeSpace() >= product.getAvailableQuantity())
					{
						int countPreviousCells = sections[posSection].getShelf()[posShelf + 1].getCells().size();
						Storage copyProduct = product;
						if (sections[posSection].getShelf()[posShelf + 1].getCells()[countPreviousCells - 1].getFreeCapacity() != 0)
						{
							copyProduct.setAvailableQuantity(product.getAvailableQuantity() - sections[posSection].getShelf()[posShelf + 1].getCells()[countPreviousCells - 1].getFreeCapacity());
							sections[posSection].getShelf()[posShelf + 1].getCells()[countPreviousCells - 1].setCellCapacity(50.0, 0.0);
						}
						if (sections[posSection].getShelf()[posShelf + 1].getCells().size() < 4)
						{
							sections[posSection].getShelf()[posShelf + 1].setBusyCells(copyProduct);
						}
						else
						{
							sections[posSection].getShelf()[posShelf + 1].getCells()[sections[posSection].getShelf()[posShelf + 1].getCells().size() - 1].setCellCapacity(50.0, 0.0);
						}
						string shelf = to_string(posShelf + 2);
						string numeric = to_string(sections[posSection].getShelf()[posShelf].getCells().size() + countPreviousCells) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size() + sections[posSection].getShelf()[posShelf + 1].getCells().size());
						Location newLoc = Location(posSection + 1, shelf, numeric);
						product.setLocation(newLoc);
						sections[posSection].getShelf()[posShelf + 1].pushProduct(product);
						storageProducts.push_back(product);
					}
					else
					{
						printMessages(4);
					}
				}
			}
			else
			{
				Storage firstProduct = product;
				firstProduct.setAvailableQuantity(sections[posSection].getShelf()[posShelf].getFreeSpace());
				Storage secondProduct = product;
				secondProduct.setAvailableQuantity(product.getAvailableQuantity() - sections[posSection].getShelf()[posShelf].getFreeSpace());
				Storage copyProduct = firstProduct;
				int countPreviousCells = sections[posSection].getShelf()[posShelf].getCells().size();
				if (sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity() != 0)
				{
					copyProduct.setAvailableQuantity(firstProduct.getAvailableQuantity() - sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].getFreeCapacity());
					sections[posSection].getShelf()[posShelf].getCells()[countPreviousCells - 1].setCellCapacity(50.0, 0.0);
				}
				if (sections[posSection].getShelf()[posShelf].getCells().size() < 4)
				{
					sections[posSection].getShelf()[posShelf].setBusyCells(copyProduct);
				}
				else
				{
					sections[posSection].getShelf()[posShelf].getCells()[sections[posSection].getShelf()[posShelf].getCells().size() - 1].setCellCapacity(50.0, 0.0);
				}
				sections[posSection].getShelf()[posShelf + 1].setBusyCells(secondProduct);
				string shelf = to_string(posShelf + 1) + "-" + to_string(posShelf + 2);
				string numeric = to_string(countPreviousCells) + "-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size() + sections[posSection].getShelf()[posShelf + 1].getCells().size());
				Location newLoc = Location(posSection + 1, shelf, numeric);
				firstProduct.setLocation(newLoc);
				secondProduct.setLocation(newLoc);
				product.setLocation(newLoc);
				sections[posSection].getShelf()[posShelf].pushProduct(firstProduct);
				sections[posSection].getShelf()[posShelf + 1].pushProduct(secondProduct);
				storageProducts.push_back(product);
			}
		}
	}
	else if (avaiQuan > CAPACITY_QUANTITY && avaiQuan <= 2 * CAPACITY_QUANTITY)
	{
		Storage firstProduct = product;
		Storage secondProduct = product;
		firstProduct.setAvailableQuantity(CAPACITY_QUANTITY);
		secondProduct.setAvailableQuantity(product.getAvailableQuantity() - CAPACITY_QUANTITY);
		sections[posSection].getShelf()[posShelf].setBusyCells(firstProduct);
		sections[posSection].getShelf()[posShelf + 1].setBusyCells(secondProduct);
		string shelf = to_string(posShelf + 1) + "-" + to_string(posShelf + 2);
		string numeric = "1-" + to_string(sections[posSection].getShelf()[posShelf].getCells().size() + sections[posSection].getShelf()[posShelf + 1].getCells().size());
		Location newLoc = Location(posSection + 1, shelf, numeric);
		firstProduct.setLocation(newLoc);
		secondProduct.setLocation(newLoc);
		product.setLocation(newLoc);
		sections[posSection].getShelf()[posShelf].pushProduct(firstProduct);
		sections[posSection].getShelf()[posShelf + 1].pushProduct(secondProduct);
		storageProducts.push_back(product);
	}
}

void removeProduct(Section*& sections, vector<Storage>& storageProducts, vector<string>& logs, const char* productName, float quantity, int count)
{
	int posShelf = 0;
	int posSection = 0;
	bool isHere = false;
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = 0; j < CAPACITY_SHELF; j += 2)
		{
			for (size_t z = 0; z < sections[i].getShelf()[j].getProducts().size(); z++)
			{
				if (strcmp(sections[i].getShelf()[j].getProducts()[z].getProductName(), productName) == 0)
				{
					posSection = i;
					posShelf = j;
					isHere = true;
					break;
				}
			}
			if (isHere)
			{
				break;
			}
		}
	}
	float productsQuantity = sections[posSection].getShelf()[posShelf].getBusySpace() + sections[posSection].getShelf()[posShelf + 1].getBusySpace();
	if (productsQuantity >= quantity)
	{
		vector<Storage> rearrangeProducts;
		rearrange(sections, posSection, posShelf, rearrangeProducts);
		for (size_t i = 0; i < rearrangeProducts.size() - 1; i++)
		{
			for (size_t j = 0; j < rearrangeProducts.size() - i - 1; j++)
			{
				if (rearrangeProducts[j].getExpirationDate() >= rearrangeProducts[j + 1].getExpirationDate())
				{
					swap(rearrangeProducts[j], rearrangeProducts[j + 1]);
				}
			}
		}
		removeProductFromListProducts(storageProducts, rearrangeProducts);
		string unitProduct = rearrangeProducts[0].getUnit();
		addLog(logs, "remove", productName, unitProduct, quantity);
		for (size_t i = 0; i < rearrangeProducts.size(); i++)
		{
			if (quantity != 0)
			{
				if (rearrangeProducts[i].getAvailableQuantity() <= quantity)
				{
					cout << "\nА batch of the product " << productName << " with quantity " << rearrangeProducts[i].getAvailableQuantity() << " has been removed with an expiration date " << rearrangeProducts[i].getExpirationDate() << " located on " << rearrangeProducts[i].getLocation() << endl;
					quantity -= rearrangeProducts[i].getAvailableQuantity();
					rearrangeProducts.erase(rearrangeProducts.begin() + i);
					i--;
				}
				else if (rearrangeProducts[i].getAvailableQuantity() > quantity)
				{
					rearrangeProducts[i].setAvailableQuantity(rearrangeProducts[i].getAvailableQuantity() - quantity);
					cout << "\nPart of the product batch " << productName << " with quantity " << quantity << " has been removed with an expiration date " << rearrangeProducts[i].getExpirationDate() << " located on " << rearrangeProducts[i].getLocation() << endl;
					quantity -= quantity;
				}
			}
			else
			{
				break;
			}
		}
		clearShelfs(sections, posSection, posShelf);
		for (size_t i = 0; i < rearrangeProducts.size(); i++)
		{
			addGetProduct(sections, storageProducts, rearrangeProducts[i], posSection, posShelf);
		}
	}
	else
	{
		string yesOrNo;
		float allQuantity = 0.0;
		vector<Date> expirationDates;
		vector<Storage> rearrangeProducts;
		rearrange(sections, posSection, posShelf, rearrangeProducts);
		for (size_t i = 0; i < rearrangeProducts.size(); i++)
		{
			expirationDates.push_back(rearrangeProducts[i].getExpirationDate());
			allQuantity += rearrangeProducts[i].getAvailableQuantity();
		}
		printLine();
		cout << "Product Name: " << productName << endl;
		cout << "Available Quantity: " << allQuantity << endl;
		for (size_t i = 0; i < expirationDates.size(); i++)
		{
			cout << expirationDates[i] << "-";
		}
		cout << endl;
		printLine();
		printInputMessasges(12);
		cin >> yesOrNo;
		yesOrNo = to_lower(yesOrNo);
		if (yesOrNo == "yes")
		{
			removeProductFromListProducts(storageProducts, rearrangeProducts);
			clearShelfs(sections, posSection, posShelf);
			cout << endl;
			for (size_t i = 0; i < rearrangeProducts.size(); i++)
			{
				cout << rearrangeProducts[i] << endl;
			}
			string unitProduct = rearrangeProducts[0].getUnit();
			addLog(logs, "remove", productName, unitProduct, allQuantity);
			rearrangeProducts.clear();
		}
		else
		{
			printMessages(5);
		}
	}
}