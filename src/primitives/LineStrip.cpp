#include "primitives/LineStrip.hpp"

namespace primitives {
    LineStrip::LineStrip() {
        vertices.setPrimitiveType(sf::PrimitiveType::LinesStrip);
    }

    LineStrip::LineStrip(const std::vector<sf::Vector2f>& points) {
        vertices.setPrimitiveType(sf::PrimitiveType::LinesStrip);
        for (auto& p : points) {
            vertices.append(sf::Vertex{p});
        }
    }

    void LineStrip::setLineColor(const sf::Color& color) {
        for (size_t i = 0; i < vertices.getVertexCount(); i++) {
            vertices[i].color = color;
        }
    }

    void LineStrip::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(vertices, states);
    }
} // namespace primitives