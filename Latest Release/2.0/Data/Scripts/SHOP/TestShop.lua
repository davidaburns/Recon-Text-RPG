--TestShop Lua Script

DialogText("Hello, <Player Name>.\nWelcome to TestShop, what would you like to do?\n")
DisplayMenu("Buy", "Sell", "Exit")

a = MenuSelect()

if a == 0 then 
	Print("You chose to buy.(test, suppose to call buy function)") 
end
if a == 1 then 
	Print("You chose to sell.(test, suppose to call buy function)") 
end
if a == 2 then 
	DialogText("Goodby, <Player Name>.\nThank you for coming.\n")
end