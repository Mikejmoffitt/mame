// license:BSD-3-Clause
// copyright-holders:smf
#ifndef MAME_MACHINE_DS128X_H
#define MAME_MACHINE_DS128X_H

#include "mc146818.h"

#define MCFG_DS12885_ADD(_tag) \
	MCFG_DEVICE_ADD(_tag, DS12885, XTAL(32'768))

#define MCFG_DS12885EXT_ADD(_tag) \
	MCFG_DEVICE_ADD(_tag, DS12885EXT, XTAL(32'768))

// ======================> ds12885_device

class ds12885_device : public mc146818_device
{
public:
	// construction/destruction
	ds12885_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock = 32'768);
	ds12885_device(const machine_config &mconfig, device_type type, const char *tag, device_t *owner, uint32_t clock = 32'768);

protected:
	virtual int data_size() override { return 128; }
	virtual int get_timer_bypass() override;
};

// device type definition
DECLARE_DEVICE_TYPE(DS12885, ds12885_device)

// ======================> ds12885ext_device

class ds12885ext_device : public ds12885_device
{
public:
	// construction/destruction
	ds12885ext_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock = 32'768);

	// read/write access to extended ram
	DECLARE_READ8_MEMBER(read_extended);
	DECLARE_WRITE8_MEMBER(write_extended);

protected:
	virtual int data_size() override { return 256; }
};

// device type definition
DECLARE_DEVICE_TYPE(DS12885EXT, ds12885ext_device)

#endif // MAME_MACHINE_DS128X_H
