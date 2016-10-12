#pragma once
namespace engine {
	namespace core {
		class EngineConfig {
		public:
			EngineConfig(bool fullscreen, int resolution_width, int resolution_height, bool vsync, int num_vblank);
			EngineConfig(EngineConfig& other);

			int getResolutionWidth();
			int getResolutionHeight();
			bool getFullscreen();
			bool getVsync();
			int getNumVBlank();

			void setResolutionWidth(int width);
			void setResolutionHeight(int height);
			void setFullscreen(bool fullscreen);
			void setVsync(bool vsync);
			void setNumVBlank(int num_vblank);

		private:
			int resolution_width;
			int resultion_height;
			bool window_fullscreen;
			bool vsync;
			int num_vblank;
		};
	}
}