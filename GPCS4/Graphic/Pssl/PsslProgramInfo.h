#pragma once

#include "GPCS4Common.h"
#include "PsslShaderStructure.h"
#include "PsslKey.h"

namespace pssl
{;

// Data is not persistent,
// you can't use this class after code is free.

class PsslProgramInfo
{
public:
	PsslProgramInfo(uint8_t* code);
	~PsslProgramInfo();

	uint32_t getCodeSizeBytes() const;

	uint32_t getCodeSizeDwords() const;

	bool hasFetchShader();

	uint32_t getShaderType() const;

	PsslKey getKey() const;

	uint32_t getInputUsageSlotCount() const;

	const InputUsageSlot* getInputUsageSlot(uint32_t idx) const;

private:
	bool initBinaryInfo(uint8_t* code);

private:
	const ShaderBinaryInfo* m_shaderBinaryInfo;
	const InputUsageSlot* m_inputUsageSlots;
};

// return UINT_MAX means no fetch shader
uint32_t getFetchShaderStartRegister(const PsslProgramInfo& progInfo);

}
