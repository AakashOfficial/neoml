/* Copyright © 2017-2020 ABBYY Production LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
--------------------------------------------------------------------------------------------------------------*/

#pragma once

#include "Node.h"

namespace NeoOnnx {

class CGraphInput : public CNode {
public:
	CGraphInput( const onnx::ValueInfoProto& input, CMap<CString, CInputInfo>& nodeOutputs );

	// CNode methods' realizations.
	virtual void OnnxReshape() override;
	virtual void MarkTensorDims() override {}
	virtual void AddLayers( CDnn& dnn ) override;

	const CString& Name() const { return name; }

private:
	const CString name;
	const onnx::ValueInfoProto& valueInfo;
};

} // namespace NeoOnnx
