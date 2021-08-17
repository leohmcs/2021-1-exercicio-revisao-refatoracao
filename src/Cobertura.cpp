#include "Cobertura.hpp"
#include "Imovel.hpp"

#include <iostream>
#include <iomanip>


Cobertura::Cobertura(double _area, double _valor_m2, int _num_quartos, int _num_banheiros, int _num_vagas, 
            Cliente _vendedor, std::string _corretor) {
    this->set_area(_area);
    this->set_valor_m2(_valor_m2);
    this->set_num_quartos(_num_quartos);
    this->set_num_banheiros(_num_banheiros);
    this->set_num_vagas(_num_vagas);
    this->set_vendedor(_vendedor);
    this->set_corretor(_corretor);
}

void Cobertura::print() {
    std::cout << "[Cobertura]" << std::endl;
    Imovel::print();
    std::cout << "Area: " << get_area() << std::endl
            << "  Quartos: " << get_num_quartos() << std::endl
            << "  Banheiros: " << get_num_banheiros() << std::endl
            << "  Vagas: " << get_num_vagas() << std::endl
            << "Taxa de Comissão: " << std::fixed << std::setprecision(0) << get_taxa_comissao() * 100 << "%" << std::endl
            << "Valor Comissão: R$ " << std::fixed << std::setprecision(2) << comissao() << std::endl
            << "Valor de Venda: R$ " << std::fixed << std::setprecision(2) << valor_de_venda() << std::endl;
}

double Cobertura::get_taxa_comissao() {
    return TAXA_COMISSAO;
}

double Cobertura::comissao() {
    return valor() * get_taxa_comissao();
}

double Cobertura::valor_de_venda() {
    return valor() + comissao();
}