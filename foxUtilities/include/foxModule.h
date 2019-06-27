#pragma once

/**
 * Includes
 */
#include "foxPrerequisitesUtilities.h"

namespace foxEngineSDK
{

  /**
   * @brief Represents one
   */
  template <class T>
  class Module
  {
  public:

    /**
     * @brief Returns a reference to the module instance. Module has to have
     *        been started up first otherwise an exception will be thrown.
     */
    static T&
      instance()
    {

      if (!isStartedUp())
      {
        //TODO: should send an exception. will be set when foxException gets created.
      }

      if (isDestroyed())
      {
        //TODO: should send an exception. will be set when foxException gets created.
      }

      return *_instance();
    }

    static T*
      instancePtr()
    {

      if (!isStartedUp())
      {
        //TODO: should send an exception. will be set when foxException gets created.
      }

      if (isDestroyed())
      {
        //TODO: should send an exception. will be set when foxException gets created.
      }

      return _instance();
    }

    /**
     * @brief Constructs and starts the module using the specified parameters.
     */
    template <class... Args>
    static void
      startUp(Args&& ...args)
    {

      if (isStartedUp())
      {
        //TODO: should send an exception. will be set when foxException gets created.
      }

      _instance() = new T(std::forward<Args>(args)...);
      isStartedUp() = true;

      static_cast<Module*>(_instance())->onStartUp();
    }

    /**
     * @brief
     */
    template<class SubType, class... Args>
    static void
      startUp(Args&& ...args)
    {
      static_assert(std::is_base_of<T, SubType>::value,
        "Provided type isn't derived from type the Module is initialized");

      if (isStartedUp())
      {
        //TODO: should send an exception. will be set when foxException gets created.
      }

      _instance() = new SubType(std::forward<Args>(args)...);
      isStartedUp() = true;

      static_cast<Module*>(_instance())->onStartUp();
    }

    /**
     * @brief
     */
    static void
      shutDown()
    {
      if (isDestroyed())
      {
        //TODO: should send an exception. will be set when foxException gets created.
      }

      if (!isStartedUp())
      {
        //TODO: should send an exception. will be set when foxException gets created.
      }

      static_cast<Module*>(_instance())->onShutDown();

      delete _instance();
      isDestroyed() = true;
    }

    /**
     * @brief Query if the module has been started.
     */
    static bool
      isStarted()
    {
      return isStartedUp() && !isDestroyed();
    }

  protected:
    Module() = default;

    virtual ~Module() = default;

    Module(Module&&) = delete;

    Module(const Module&) = delete;

    Module& operator=(Module&&) = delete;

    Module& operator=(const Module&) = delete;

    /**
     * @brief Override if you want your module to be notified once it has been
     *        constructed and started.
     */
    virtual void
      onStartUp() {}

    /**
    * @brief Override if you want your module to be notified just before it is deleted.
    * @note  Useful when your module is polymorphic and you might want to perform
    *        some kind of clean up perhaps overriding that of a base class.
    */
    virtual void
      onShutDown() {}

    /**
     * @brief
     */
    static T*&
      _instance()
    {
      static T* inst = nullptr;
      return inst;
    }

    /**
     * @brief Checks has the Module been shut down.
     * @note If module was never even started, this will return false.
     */
    static bool&
      isDestroyed()
    {
      static bool inst = nullptr;
      return inst;
    }

    /**
     * @brief Checks has the Module been started up.
     */
    static bool&
      isStartedUp()
    {
      static bool inst = nullptr;
      return inst;
    }
  };
}
