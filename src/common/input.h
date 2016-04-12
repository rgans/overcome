#ifndef RRG_INPUT_H
#define RRG_INPUT_H

#pragma once

#if defined(__ANDROID__) || defined(ANDROID)
#define RRG_INPUT_PLATFORM_ANDROID
#define RRG_INPUT_LIBEXPORT
#elif defined(__linux) || defined(__linux__) || defined(linux) || defined(LINUX)
#define RRG_INPUT_PLATFORM_LINUX
#define RRG_INPUT_LIBEXPORT
#elif defined(_WIN32) || defined(__WIN32__) || defined(_MSC_VER)
#define RRG_INPUT_PLATFORM_WIN
#if defined(RRG_INPUT_LIB_DYNAMIC)
#define RRG_INPUT_LIBEXPORT		__declspec(dllexport)
#elif defined(RRG_INPUT_LIB_DYNAMIC_USE)
#define RRG_INPUT_LIBEXPORT		__declspec(dllimport)
#else
#define RRG_INPUT_LIBEXPORT
#endif
#elif defined(__APPLE__)
#define RRG_INPUT_LIBEXPORT
#include <TargetConditionals.h>
#define RRG_INPUT_PLATFORM_MAC
#else
#error input: Unknown/unsupported platform!
#endif


#define RRG_INPUT_TEXT_INPUT_QUEUE_LENGTH 32

#include <cassert>
#include <cstring>
#include <new>

#define RRG_INPUT_ASSERT assert
#define RRG_INPUT_UNUSED(x) (void)(x)

#if defined(GAINPUT_PLATFORM_LINUX)

#include <cstdlib>
#include <stdint.h>

union _XEvent;
typedef _XEvent XEvent;

#elif defined(GAINPUT_PLATFORM_WIN)

#include <cstdlib>

typedef struct tagMSG MSG;

namespace gainput
{
	typedef unsigned __int8 uint8_t;
	typedef __int8 int8_t;
	typedef unsigned __int32 uint32_t;
	typedef unsigned __int64 uint64_t;
}

#elif defined(RRG_INPUT_PLATFORM_ANDROID)

#include <stdint.h>
struct AInputEvent;

#endif

/// ID of an input device.
typedef unsigned int DeviceId;
/// ID of a specific button unique to an input device.
typedef unsigned int DeviceButtonId;

/// Describes a device button on a specific device.
struct DeviceButtonSpec
{
	/// ID of the input device.
	DeviceId deviceId;
	/// ID of the button on the given input device.
	DeviceButtonId buttonId;
};

/// ID of a user-defined, mapped button.
typedef unsigned int UserButtonId;
/// ID of an input listener.
typedef unsigned int ListenerId;
/// ID of a device state modifier.
typedef unsigned int ModifierId;

/// An invalid device ID.
static const DeviceId InvalidDeviceId = -1;
/// An invalid device button ID.
static const DeviceButtonId InvalidDeviceButtonId = -1;
/// An invalid user button ID.
static const UserButtonId InvalidUserButtonId = -1;

class InputDeltaState;
class InputListener;
class InputManager;
class DebugRenderer;
class DeviceStateModifier;

template <class T> T Abs(T a) { return a < T() ? -a : a; }

#endif