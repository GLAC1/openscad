/*
 * The MIT License
 *
 * Copyright (c) 2016-2018, Torsten Paul <torsten.paul@gmx.de>,
 *                          Marius Kintel <marius@kintel.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#pragma once

#include "shape.h"

namespace libsvg {

class svgpage : public shape {
protected:
    length_t width;
    length_t height;
	viewbox_t viewbox;
	alignment_t alignment;

public:
    svgpage();
    ~svgpage() override;

    const length_t& get_width() const { return width; }
    const length_t& get_height() const { return height; }
	const viewbox_t& get_viewbox() const { return viewbox; }
	const alignment_t& get_alignment() const { return alignment; }
    bool is_container() const override { return true; }
    
    void set_attrs(attr_map_t& attrs) override;
    const std::string dump() const override;
    const std::string& get_name() const override { return svgpage::name; };
    
    static const std::string name;

	shape* clone() const override { return new svgpage(*this); };
};

}
