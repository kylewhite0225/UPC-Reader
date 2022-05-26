# CS300 - Data Structures - Assignment 5
# A Simple Barcode Reader Application

This program is a simple a "barcode reader" application. An input file with items with their UPC codes and descriptions is provided. The Universal Product Code (UPC) is a barcode symbology that is widely used for tracking trade items in stores. UPC consists of numeric digits, that are uniquely assigned to each trade item. The data is obtained from http://www.grocery.com/open-grocery-database-project/.

The file is read into a binary search tree (key: UPC, value: description of item), and the functionality of this program allows the user to search by UPC. It also prints the total time to complete the search and handles errors for invalid input.

Sample runs are provided below:
 
**Sample Run-1:**  
> UPC Code: 657622604842    
> Honest Tea Peach White Tea    
> Lookup time: 1 miliseconds  

**Sample Run-2:**    
> UPC Code: 071072030035   
> Coffee Espresso Decaf  
> Lookup time: 10 miliseconds  

**Sample Run-3:**   
> UPC Code: 1111   
> Not found   
