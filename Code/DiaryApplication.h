﻿#pragma once

#include <FrameCore/IApplication.h>

class CDiaryApplication final : public Frame::IApplication {

protected:
	
	virtual void Initialize(int argc, char ** argv) override;

};