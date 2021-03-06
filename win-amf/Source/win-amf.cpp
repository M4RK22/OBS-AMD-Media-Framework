/*
MIT License

Copyright (c) 2016 Michael Fabian Dirks

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once
//////////////////////////////////////////////////////////////////////////
// Includes
//////////////////////////////////////////////////////////////////////////
#include "win-amf.h"

// Plugin
#include "amf-vce-capabilities.h"
#include "enc-h264.h"
#include "enc-h264-simple.h"

//////////////////////////////////////////////////////////////////////////
// Code
//////////////////////////////////////////////////////////////////////////
using namespace AMFEncoder;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
	return TRUE;
}

OBS_DECLARE_MODULE();
OBS_MODULE_AUTHOR("Michael Fabian Dirks");
OBS_MODULE_USE_DEFAULT_LOCALE("win-amf", "en-US");

/**
* Required: Called when the module is loaded.  Use this function to load all
* the sources/encoders/outputs/services for your module, or anything else that
* may need loading.
*
* @return           Return true to continue loading the module, otherwise
*                   false to indicate failure and unload the module
*/
MODULE_EXPORT bool obs_module_load(void) {
	// Log Capabilities
	AMFEncoder::VCE_Capabilities::reportCapabilities();

	// Register Encoder
	AMFEncoder::VCE_H264_Encoder::encoder_register();
	AMFEncoder::VCE_H264_Simple_Encoder::encoder_register();

	return true;
}

/** Optional: Called when the module is unloaded.  */
MODULE_EXPORT void obs_module_unload(void) {}

/** Optional: Returns the full name of the module */
MODULE_EXPORT const char *obs_module_name() {
	return "AMD Media Framework Plugin";
}

/** Optional: Returns a description of the module */
MODULE_EXPORT const char *obs_module_description() {
	return "AMD Media Framework Plugin";
}