// -*- indent-tabs-mode: nil; -*-

#ifndef _SetEjectDelay_h
#define _SetEjectDelay_h

#include "base.hpp"

// http://developer.apple.com/documentation/Darwin/Conceptual/KEXTConcept/KEXTConceptIOKit/hello_iokit.html#//apple_ref/doc/uid/20002366-CIHECHHE
class org_pqrs_driver_SetEjectDelay : public IOService
{
  OSDeclareDefaultStructors(org_pqrs_driver_SetEjectDelay);

public:
  virtual bool init(OSDictionary *dictionary = 0);
  virtual void free(void);
  virtual IOService *probe(IOService *provider, SInt32 *score);
  virtual bool start(IOService *provider);
  virtual void stop(IOService *provider);

  static void customizeAllKeymap(void);

private:
  enum {
    MAXNUM_KEYBOARD = 4,
  };

  // ------------------------------------------------------------
  struct HookedKeyboard {
    IOHIKeyboard *kbd;
#include "generate/output/include.code.hpp"

    void initialize(IOHIKeyboard *p);
    void terminate(void);
    void refresh(void);
  };
  static HookedKeyboard hookedKeyboard[MAXNUM_KEYBOARD];
  static HookedKeyboard *new_hookedKeyboard(void);
  static HookedKeyboard *search_hookedKeyboard(const IOHIKeyboard *kbd);

  static bool notifier_hookKeyboard(org_pqrs_driver_SetEjectDelay *self, void *ref, IOService *newService);
  static bool notifier_unhookKeyboard(org_pqrs_driver_SetEjectDelay *self, void *ref, IOService *newService);

  static bool customizeKeyMap(IOHIKeyboard *kbd);
  static bool restoreKeyMap(IOHIKeyboard *kbd);

  IONotifier *keyboardNotifier;
  IONotifier *terminatedNotifier;
};

#endif
