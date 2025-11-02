#ifndef __CUDA_RENDERER_H__
#define __CUDA_RENDERER_H__

#include "circleRenderer.h"

class CudaRenderer : public CircleRenderer {
 private:
  Image* image;
  SceneName sceneName;

  int numCircles;
  float* position;
  float* velocity;
  float* color;
  float* radius;

  int* binIntersectionCounts;
  int* binIntersectionCountsCopy;
  int binIntersectionCountsSize;
  int* binIntersectionSums;
  int* binCircleIntersections;
  int binCircleIntersectionsSize;
  int numBinsX;
  int numBinsY;
  int numBins;

  float* cudaDevicePosition;
  float* cudaDeviceVelocity;
  float* cudaDeviceColor;
  float* cudaDeviceRadius;
  float* cudaDeviceImageData;

 public:
  CudaRenderer();
  virtual ~CudaRenderer();

  const Image* getImage();

  void setup();

  void exclusiveScan(int N, int* result, int threads_per_block);

  void loadScene(SceneName name, int seed = 0);

  void allocOutputImage(int width, int height);

  void clearImage();

  void advanceAnimation();

  void render();

  void shadePixel(int circleIndex, float pixelCenterX, float pixelCenterY,
                  float px, float py, float pz, float* pixelData);
};

#endif