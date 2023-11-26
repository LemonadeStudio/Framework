﻿#pragma once

#include <chrono> // for m_maxFrameDelay

struct GLFWwindow;

namespace Frame {

	struct IApplication {
	protected:
		GLFWwindow * m_pWindow = nullptr;

	public:
		int EntryPoint(int argc, char ** argv) {
			if(!InitializeWindow("Framework", 800, 600)) {
				// TODO
				Terminate();
				return -1;
			}
			
			SetVSync(true);

			Initialize(argc, argv);
			Run();
			return 0;
		}

		void Terminate();

	protected:

		bool InitializeWindow(const char * title, int windowWidth, int windowHeight);
		void Run();

		virtual void Initialize(int argc, char ** argv) = 0;

		virtual void MainLoopPriority() {}
		virtual void MainLoopLast() {}

		bool GetVSync() const { return m_bVSync; }
		void SetVSync(bool bEnable);

		int GetMaxFPS() const { return m_maxFPS; }
		// 0 = 无限大 | Infinite
		void SetMaxFPS(int fps) {
			m_maxFPS = fps > 0 ? fps : 0;

			if(m_maxFPS != 0) {
				m_maxFrameDelay = std::chrono::microseconds(1000000 / fps);
			}
		}

		int m_maxFPS = 0;

		bool m_quit = false;

	private:
		bool m_bVSync = true;
		std::chrono::microseconds m_maxFrameDelay { 0 };

	};

}