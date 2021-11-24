/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkPipeline_h
#define itkPipeline_h

#include <CLI/App.hpp>
#include <CLI/Formatter.hpp>
#include <CLI/Config.hpp>

#include "itkWASMOutputImage.h"

#define ITK_WASM_PARSE(pipeline, argc, argv) \
    try { \
        pipeline.parse(argc, argv); \
    } catch(const CLI::ParseError &e) { \
        return pipeline.exit(e); \
    }

namespace itk {

template <typename TImage>
bool lexical_cast(const std::string &input, WASMOutputImage<TImage> &outputImage)
{
  outputImage.SetIdentifier(input);
  return true;
}

namespace wasm {

// Importing into the itk namespace the main classes from CLI11
using CLI::App;
using CLI::ExistingDirectory;
using CLI::ExistingFile;
using CLI::ExitCodes;
using CLI::FileError;
using CLI::NonexistentPath;
using CLI::Option;
using CLI::ParseError;
using CLI::Success;
using CLI::Formatter;
using CLI::Config;

class ITKFormatter : public CLI::Formatter
{
  public:
    ITKFormatter() : Formatter() {}
    std::string make_description(const CLI::App * app) const override;
};

class Pipeline: public CLI::App
{
public:
    /** Make a new Pipeline application. */
    Pipeline(std::string description, int argc, char **argv);

    /** Shortcut for the lazy. */
    Pipeline(int argc, char **argv)
        : Pipeline("", argc, argv) {}

    /** Exit. */
    auto exit(const CLI::Error &e) -> int;

    static auto GetUseMemoryIO()
    {
      return m_UseMemoryIO;
    }

    ~Pipeline() override;
private:
    static bool m_UseMemoryIO;
    int m_argc;
    char **m_argv;
};

} // end namespace wasm
} // end namespace itk

#endif
