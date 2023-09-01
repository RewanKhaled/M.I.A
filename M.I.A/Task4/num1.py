import random

class Weapon:
    def __init__(self, name, damage, special_effect=None):
        self.name = name
        self.damage = damage
        self.special_effect = special_effect

class Shield:
    def __init__(self, name, cost, save_percentage):
        self.name = name
        self.cost = cost
        self.save_percentage = save_percentage

class Character:
    def __init__(self, name, health, energy, shields, weapons):
        self.name = name
        self.health = health
        self.energy = energy
        self.shields = shields
        self.weapons = weapons
        self.active_shield = None

    def select_shield(self):
        # Choose a shield randomly from available shields.
        self.active_shield = random.choice(self.shields)
        # Reduce energy by the chosen shield's cost.
        self.energy -= self.active_shield.cost

    def attack(self, opponent):
        # Choose a weapon randomly from available weapons.
        selected_weapon = random.choice(self.weapons)
        # Generate random damage within the weapon's damage range.
        damage = random.randint(0, selected_weapon.damage)

        if selected_weapon.special_effect == "reduce_next_attack":
            # If the weapon has a special effect, reduce the opponent's shield.
            opponent.active_shield.save_percentage -= 0.2
        else:
            # Otherwise, deduct damage from the opponent's health.
            opponent.health -= damage

    def defend(self):
        # Choose a shield to defend with.
        self.select_shield()
        # Ensure the shield's save percentage doesn't go below 0.
        self.active_shield.save_percentage = max(0, self.active_shield.save_percentage)

    def is_defeated(self):
        # Check if the character's health is 0 or below.
        return self.health <= 0

class Villain(Character):
    def __init__(self, name, health, energy, shields, weapons):
        super().__init__(name, health, energy, shields, weapons)

class Gru(Villain):
    def __init__(self):
        # Define Gru's weapons and shields.
        weapons = [
            Weapon("Freeze Gun", 10, "reduce_next_attack"),
            Weapon("Electric Prod", 8),
            Weapon("Mega Magnet", 12),
            Weapon("Kalman Missile", 15)
        ]
        shields = [
            Shield("Energy Projected Barrier", 5, 0.5),
            Shield("Selective Permeability", 3, 0.3)
        ]
        super().__init__("Gru", 100, 50, shields, weapons)

class Vector(Villain):
    def __init__(self):
        # Define Vector's weapons and shields.
        weapons = [
            Weapon("Freeze Gun", 10, "reduce_next_attack"),
            Weapon("Electric Prod", 8),
            Weapon("Mega Magnet", 12),
            Weapon("Kalman Missile", 15)
        ]
        shields = [
            Shield("Energy Net Trap", 4, 0.4),
            Shield("Quantum Deflector", 6, 0.6)
        ]
        super().__init__("Vector", 100, 50, shields, weapons)

def main():
    gru = Gru()
    vector = Vector()

    while not gru.is_defeated() and not vector.is_defeated():
        # Gru attacks Vector, Vector defends.
        gru.attack(vector)
        vector.defend()

        if not vector.is_defeated():
            # Vector attacks Gru, Gru defends.
            vector.attack(gru)
            gru.defend()

    # Determine the winner and print the result.
    if gru.is_defeated():
        print("Vector wins!")
    else:
        print("Gru wins!")

if __name__ == "__main__":
    main()
