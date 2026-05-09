#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

namespace {

using Health = std::uint8_t;

constexpr std::uint8_t MAX_HEALTH = 100;

struct Monster {
 public:
  enum class Type : std::uint8_t { Slime, Orgre, Dragon };

  // Constructor
  Monster(std::string name, Monster::Type type, std::uint8_t health)
      // uses std::move to efficiently transfer ownership of the string
      : name_{std::move(name)}, type_{type}, health_{health} {
    if (health > MAX_HEALTH) {
      throw std::range_error("health must be between 0 and 100");
    }
  }

  // Getters (read-only access)
  [[nodiscard]] auto getName() const -> const std::string & { return name_; }
  [[nodiscard]] auto getType() const -> Type { return type_; }
  [[nodiscard]] auto getTypeAsStringView() const -> std::string_view {
    switch (type_) {
      case Type::Slime:
        return "Slime";
      case Type::Orgre:
        return "Orgre";
      case Type::Dragon:
        return "Dragon";
      default:
        throw "invalid monster type";
    }
  }
  [[nodiscard]] auto getHealth() const -> Health { return health_; }

 private:
  std::string name_;
  Type type_;
  Health health_;
};  // namespace

auto operator<<(std::ostream &out, const Monster &monster) -> std::ostream & {
  return out << "Monster(name=" << monster.getName()
             << ", health=" << std::to_string(monster.getHealth())
             << ", type=" << monster.getTypeAsStringView() << ")";
};

}  // namespace

// TODO handle exceptions properly
// NOLINTNEXTLINE(bugprone-exception-escape)
auto main() -> int {
  Monster const bork{"Bork", Monster::Type::Dragon, 90};
  Monster const torg{"Torg", Monster::Type::Orgre, 45};
  Monster const blurp{"Blurp", Monster::Type::Slime, 23};

  std::cout << bork << "\n";
  std::cout << torg << "\n";
  std::cout << blurp << "\n";

  return 0;
}
