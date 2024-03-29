#ifndef AUTH_MANAGER_HPP
#define AUTH_MANAGER_HPP

#include <cpprealm/sdk.hpp>

class AuthManager {
 public:
  struct Delegate {
    virtual ~Delegate() = default;
    virtual void onLoggedIn() = 0;
    virtual void onLoggedOut() = 0;
  };

  explicit AuthManager(Delegate *delegate, realm::App *app);

  void registerUser(std::string const& userEmail, std::string const& userPassword);

  void logIn(std::string const& userEmail, std::string const& userPassword);

  void logOut();

 private:
  Delegate *_delegate{nullptr};
  realm::App *_app{nullptr};
};

#endif
