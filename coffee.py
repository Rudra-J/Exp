MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    }
}

resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
}

coins = {
    "penny": 0.01,
    "dime": 0.1,
    "nickel": 0.05,
    "quarter": 0.25
}
n = True
while n:
    a = input("What do you want(espresso,latte,cappuccino): ")
    if a == 'report':
        for i in resources:
            print(f"{i}: {resources[i]}")
    else:
        price = MENU[a]["cost"]
        ing = MENU[a]['ingredients']
        flag = True
        for i in ing:
            if ing[i] > resources[i]:
                flag = False
                print(f"insufficient {i}")

        mon=0
        if flag:
            p = coins['penny'] * int(input("no. of pennies: "))
            d = coins['dime'] * int(input("no. of dimes: "))
            n = coins['nickel'] * int(input("no. of nickels: "))
            q = coins['quarter'] * int(input("no. of quarters: "))
            mon = p + q + d + n

        if mon >= price:
            print(f"Change: {round((mon - price), 3)}$")
            if flag:
                for i in ing:
                    (resources[i]) = int(resources[i]) - int(ing[i])
            print(f"Here is you {a}")
        else:
            print("Unsufficient funds, money refunded")



