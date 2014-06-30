#ifndef __VeilComponent__
#define __VeilComponent__

namespace Veil {

  class Component {
    std::unordered_map<const std::type_info*, Component*> components;
    public:
      Component() {};
      virtual ~Component() = default;

      // NOTE: Templates suck. They HAVE to stay in the headers.
      template <typename T> void add(T* component) {
        if (components.count(&typeid(T)) > 0) {
          return;
        }

        components[&typeid(*component)] = component;
      }

      template <typename T> T* as() const {
        if (components.count(&typeid(T)) > 0) {
          return static_cast<T*>(components.at(&typeid(T)));
        }

        return nullptr;
      }

      template <typename T> bool has() const {
        if (components.count(&typeid(T)) > 0) {
          return true;
        }

        return false;
      }

      template <typename T> void remove() {
        delete components[&typeid(T)];
        components.erase(&typeid(T));
      }
  };

}

#endif /* defined(__VeilComponent__) */
