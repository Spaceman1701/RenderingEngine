
namespace engine {
	namespace core {
		namespace render {
			namespace gl {
				class Framebuffer {
				private:
					int handle;
				public:
					~Framebuffer();
					Framebuffer();
					void attach2DColorImage(int attachment, int imageRef);
					void bind();
				};
			}
		}
	}
}