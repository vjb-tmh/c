SELECT person, address FROM customers
WHERE Country='USA' AND (City='New York' OR City='Miami') ORDER BY Country DESC;

INSERT INTO Customers (Name, Address, Country City)
VALUES('Foobar','111 Egg Street','USA','Somewhereville');

UPDATE Customers
SET Name = 'Dave', City = 'New Frampton'
WHERE ID = 1;

DELETE from Customers
where Name = 'Bill';

SELECT Person FROM Customers
WHERE Name IS NOT NULL;

SELECT top 3 * from customers;

SELECT top 50 percent from customers;

SELECT MIN(Price) as SmallestPrice
FROM Products;

SELECT MAX(PricE) as LargestPrice
FROM Products;

SELECT COUNT(ProductID)
FROM Products;

SELECT SUM(Quantity)
FROM Products;

SELECT AVG(Cost)
FROM Products;

SELECT * FROM Customers
WHERE Name LIKE 'a_%_%';  /*  Finds names that start with 'a' and have
                              at least 3 characters in them.
                                  _ matches any single character
                                  % matches 0 or more characters
                           */
SELECT * FROM Customers
WHERE Name LIKE '%z';      -- matches names that end with 'z'

SELECT * FROM Customers
WHERE Name LIKE '_erlin'

SELECT * FROM Customers
WHERE Name IN ('Dave','Steve','Mary'); -- IN is shorthand for multiple OR clauses

SELECT * FROM Customers
WHERE Name NOT IN ('Sally','Paul');

SELECT * FROM Customers
WHERE Name IN (SELECT Name FROM Vendors);

SELECT * FROM Products
WHERE ProductName BETWEEN 'Axe' AND 'Sword';

SELECT * FROM Products
WHERE (Price BETWEEN 10 AND 20)
AND NOT Category IN ('Armor','Spells');

SELECT w.WeaponID, w.WeaponName, a.ArmorID, a.ArmorName
FROM Weapons as w, Armor as a
WHERE w.Category = 'Spiked Shield' AND w.WeaponID = a.ArmorID;

SELECT o.OrderID, c.CustID, c.Name
FROM Orders as o
INNER JOIN Customers as c ON o.CustID = c.CustID;  -- get all records from both tables that match criteria

SELECT o.OrderID, c.CustID, c.Name
FROM Orders as o
LEFT JOIN Customers as c ON o.CustID = c.CustID;   -- get all orders and any customers that match the criteria

SELECT o.OrderID, c.CustID, c.Name
FROM Orders as o
RIGHT JOIN Customers as c ON o.CustID = c.CustID;  -- get all customers and any orders that match the criteria

SELECT o.OrderID, o.Cost, c.Name
FROM Orders as o
FULL JOIN Customers as c ON o.CustID = c.CustID;

SELECT City from Customers
UNION
SELECT City from Orders
ORDER BY City ASC;

SELECT Count(City), Country
from Countries
GROUP BY Country              -- get a list of the number of cities per country
ORDER BY Count(City) DESC;

