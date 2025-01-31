const extensionToIO = new Map([
  ['vtk', 'itkVTKPolyDataMeshIOJSBinding'],
  ['VTK', 'itkVTKPolyDataMeshIOJSBinding'],
  ['byu', 'itkBYUMeshIOJSBinding'],
  ['BYU', 'itkBYUMeshIOJSBinding'],
  ['fsa', 'itkFreeSurferAsciiMeshIOJSBinding'],
  ['FSA', 'itkFreeSurferAsciiMeshIOJSBinding'],
  ['fsb', 'itkFreeSurferBinaryMeshIOJSBinding'],
  ['FSB', 'itkFreeSurferBinaryMeshIOJSBinding'],
  ['obj', 'itkOBJMeshIOJSBinding'],
  ['OBJ', 'itkOBJMeshIOJSBinding'],
  ['off', 'itkOFFMeshIOJSBinding'],
  ['OFF', 'itkOFFMeshIOJSBinding'],
  ['stl', 'itkSTLMeshIOJSBinding'],
  ['STL', 'itkSTLMeshIOJSBinding']
])

export default extensionToIO
